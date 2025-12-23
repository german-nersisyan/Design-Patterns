#include "JsonToCsvConverter.h"
#include <nlohmann/json.hpp>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <string>

using json = nlohmann::json;

static std::string escapeCsv(const std::string& s) {
	if (s.find_first_of(",\"\n") == std::string::npos)
		return s;
	std::string out = "\"";
	for (char c : s) {
		if (c == '"') out += "\"\"";
		else out += c;
	}
	out += "\"";
	return out;
}

void flattenJson(const json& j, std::map<std::string, std::string>& out, const std::string& prefix = "") {
	if (j.is_object()) {
		for (auto&[k, v] : j.items()) {
			flattenJson(v, out, prefix.empty() ? k : prefix + "." + k);
		}
	}
	else if (j.is_array()) {
		if (!j.empty() && j[0].is_object()) {
			out[prefix] = "";
		}
		else {
			std::string arr;
			for (auto& el : j) {
				if (!arr.empty()) arr += ";";
				if (el.is_string()) arr += el.get<std::string>();
				else arr += el.dump();
			}
			out[prefix] = arr;
		}
	}
	else if (j.is_primitive()) {
		if (j.is_string()) out[prefix] = j.get<std::string>();
		else out[prefix] = j.dump();
	}
}

void expandJsonRow(const json& j, std::map<std::string, std::string> parent,
	std::vector<std::map<std::string, std::string>>& rows,
	const std::string& prefix = "") {
	if (!j.is_object()) {
		rows.push_back(parent);
		return;
	}

	std::map<std::string, std::string> flat;
	for (auto&[k, v] : j.items()) {
		if (v.is_array() && !v.empty() && v[0].is_object()) {
			continue;
		}
		else {
			flattenJson(json{ {k,v} }, flat);
		}
	}

	for (auto&[k, v] : flat) parent[k] = v;

	bool expanded = false;
	for (auto&[k, v] : j.items()) {
		if (v.is_array() && !v.empty() && v[0].is_object()) {
			for (auto& item : v) {
				expandJsonRow(item, parent, rows, prefix.empty() ? k : prefix + "." + k);
			}
			expanded = true;
		}
	}

	if (!expanded) rows.push_back(parent);
}

std::string JsonToCsvConverter::convertText(const std::string& input) {
	json j = json::parse(input, nullptr, true, true);

	if (j.is_object()) {
		json tmp = json::array();
		tmp.push_back(j);
		j = tmp;
	}

	if (!j.is_array() || j.empty())
		throw std::runtime_error("JSON must be object or array of objects");

	std::vector<std::map<std::string, std::string>> rows;

	for (auto& item : j) {
		expandJsonRow(item, {}, rows);
	}

	std::set<std::string> headerSet;
	for (auto& row : rows)
		for (auto&[k, _] : row) headerSet.insert(k);

	std::vector<std::string> headers(headerSet.begin(), headerSet.end());

	std::stringstream out;

	for (size_t i = 0; i < headers.size(); ++i) {
		if (i != 0) out << ",";
		out << escapeCsv(headers[i]);
	}
	out << "\n";

	for (auto& row : rows) {
		for (size_t i = 0; i < headers.size(); ++i) {
			if (i != 0) out << ",";
			if (row.count(headers[i])) out << escapeCsv(row[headers[i]]);
		}
		out << "\n";
	}

	return out.str();
}

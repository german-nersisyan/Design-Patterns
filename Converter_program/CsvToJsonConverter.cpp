#include "CsvToJsonConverter.h"
#include <sstream>
#include <vector>
#include <nlohmann/json.hpp>
#include <algorithm>

using json = nlohmann::json;

static std::string trim(const std::string& s) {
	size_t start = 0, end = s.size();
	while (start < end && (s[start] == ' ' || s[start] == '\r' || s[start] == '\n')) start++;
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\r' || s[end - 1] == '\n')) end--;
	return s.substr(start, end - start);
}

std::string CsvToJsonConverter::convertText(const std::string& input) {
	std::stringstream in(input);
	std::string line;

	std::vector<std::string> headers;
	json result = json::array();

	if (std::getline(in, line)) {
		std::stringstream ss(line);
		std::string cell;
		while (std::getline(ss, cell, ',')) {
			headers.push_back(trim(cell));
		}
	}

	while (std::getline(in, line)) {
		std::stringstream ss(line);
		std::string cell;
		json obj;
		int i = 0;

		while (std::getline(ss, cell, ',')) {
			if (i < headers.size()) {
				std::string value = trim(cell);
				std::string key = headers[i];
				std::stringstream keyStream(key);
				std::string part;
				json* current = &obj;
				std::vector<std::string> keys;

				while (std::getline(keyStream, part, '.')) keys.push_back(part);

				for (size_t k = 0; k < keys.size(); ++k) {
					if (k == keys.size() - 1) {
						if (value == "true") (*current)[keys[k]] = true;
						else if (value == "false") (*current)[keys[k]] = false;
						else {
							if (value.find(';') != std::string::npos) {
								json arr = json::array();
								std::stringstream arrStream(value);
								std::string item;
								while (std::getline(arrStream, item, ';')) arr.push_back(item);
								(*current)[keys[k]] = arr;
							}
							else {
								try {
									double num = std::stod(value);
									(*current)[keys[k]] = num;
								}
								catch (...) {
									(*current)[keys[k]] = value;
								}
							}
						}
					}
					else {
						if (!current->contains(keys[k])) (*current)[keys[k]] = json::object();
						current = &(*current)[keys[k]];
					}
				}
			}
			i++;
		}

		result.push_back(obj);
	}

	return result.dump(4);
}
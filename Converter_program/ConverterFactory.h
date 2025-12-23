#pragma once
#include <memory>
#include "IConverter.h"
#include "CsvToJsonConverter.h"
#include "JsonToCsvConverter.h"

enum class ConvertType {
	CSV_TO_JSON,
	JSON_TO_CSV
};

class ConverterFactory {
public:
	static std::unique_ptr<IConverter> create(ConvertType type) {
		if (type == ConvertType::CSV_TO_JSON)
			return std::make_unique<CsvToJsonConverter>();
		else
			return std::make_unique<JsonToCsvConverter>();
	}
};
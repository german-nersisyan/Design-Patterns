#pragma once
#include "IConverter.h"

class CsvToJsonConverter : public IConverter {
public:
	std::string convertText(const std::string& input) override;
};

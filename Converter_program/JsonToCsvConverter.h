#pragma once
#pragma once
#include "IConverter.h"

class JsonToCsvConverter : public IConverter {
public:
	std::string convertText(const std::string& input) override;
};
#pragma once
#include <string>

class IConverter {
public:
	virtual std::string convertText(const std::string& input) = 0;

	virtual ~IConverter() = default;
};
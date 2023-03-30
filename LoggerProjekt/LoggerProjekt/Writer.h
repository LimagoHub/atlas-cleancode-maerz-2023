#pragma once
#include <string>

class Writer
{

public:
	virtual auto write(const std::string& message) const -> void = 0;
};

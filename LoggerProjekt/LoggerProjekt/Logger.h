#pragma once
#include <iostream>
#include <string>
#include "Writer.h"

class Logger
{
public:
	virtual auto log(const std::string &message) const -> void = 0;
	static auto create() -> std::unique_ptr<Logger>
	{
		return std::make_unique<LoggerImpl>();
	}
};


class LoggerImpl : public Logger
{
	Writer& writer;


public:
	LoggerImpl(Writer& writer)
		: writer(writer)
	{
	}

	auto log(const std::string &message) const -> void override
	{
		const std::string prefix = "Prefix ";// Komplizierter code
		writer.write(prefix + message);
	}
};

#pragma once
#include "memory"
class Calculator
{
	public: virtual double add(double a, double b) = 0;
};

class CalculatorImpl :public Calculator
{
public:
	double add(double a, double b) override
	{
		return a + b;
	}
};

class CalculatorLogger :public Calculator
{

	std::unique_ptr<Calculator> calculator_;
public:
	CalculatorLogger(std::unique_ptr<Calculator> calculator)
		: calculator_(std::move(calculator))
	{
	}

	double add(double a, double b) override
	{
		std::cout << "Add wurde gerufen" << std::endl;
		return calculator_->add(a, b);
	}
};

class CalculatorSecure :public Calculator
{

	std::unique_ptr<Calculator> calculator_;
public:
	CalculatorSecure(std::unique_ptr<Calculator> calculator)
		: calculator_(std::move(calculator))
	{
	}

	double add(double a, double b) override
	{
		std::cout << "Du kommst hier rein" << std::endl;
		return calculator_->add(a, b);
	}
};

class CalculatorFactory
{

public:
	static std::unique_ptr<Calculator> create(bool logger, bool secure)
	{
		std::unique_ptr<Calculator> result =  std::make_unique<CalculatorImpl>();
		if(logger) result = std::unique_ptr<Calculator>(new CalculatorLogger(std::move(result)));
		if( secure) result = std::unique_ptr<Calculator>(new CalculatorSecure(std::move(result)));
		return result;
	}
};

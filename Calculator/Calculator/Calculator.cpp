// Calculator.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Calculator.h"
int main()
{
	auto calc = CalculatorFactory::create(false, true);

	
	
	std::cout << calc->add(3, 4);
}


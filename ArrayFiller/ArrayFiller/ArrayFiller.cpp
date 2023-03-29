// ArrayFiller.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <random>
#include <memory>
#include "stopwatch_impl.h"
#include "mersenne_twister_number_generator_factory.h"
#include "ThreadedArrayFactoryImpl.h"
#include "ArrayClient.h"

const auto processor_count = std::thread::hardware_concurrency();

void createAndStartArrayClient(unsigned numberOfThreads)
{
	atlas::generators::mersenne_twister_number_generator_factory generatorBuilder;
	atlas::container::ThreadedArrayFactoryImpl<std::int32_t> factory{ generatorBuilder, numberOfThreads};
	atlas::client::ArrayClient<int> client{ factory };

	client.doSomethingWithArray();
}

void startArrayClientWithTimesMessung(unsigned numberOfThreads)
{
	atlas::time::stopwatch_impl stopwatch;
	stopwatch.start();
	createAndStartArrayClient(numberOfThreads);
	stopwatch.stop();
	auto elapsedDuration = stopwatch.elapsedDuration();
	std::cout << "Dauer bei " << numberOfThreads << " ist " << elapsedDuration.count() << " millis" << std::endl;
}

int main()
{
    
    

	for(unsigned numberOfThreads = 1; numberOfThreads <= processor_count + 1; ++numberOfThreads)
	{
        startArrayClientWithTimesMessung(numberOfThreads);
	}

	
     
    std::cout << "Hello World!\n";
}




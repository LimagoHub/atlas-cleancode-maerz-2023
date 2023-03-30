// LoggerProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <memory>
class Foo
{
public:
	Foo()
	{
		std::cout << "ctor foo" << std::endl;
	}
	Foo(const Foo& other) = delete;
	virtual ~Foo()
	{
		std::cout << "dtor foo" << std::endl;
	}

	virtual void bar() {
		std::cout << "bar" << std::endl;
	}
};



int main()
{
	auto fooPtr = std::make_shared<Foo>();

	std::cout << fooPtr.use_count() << std::endl;

	auto other = fooPtr;

	std::cout << fooPtr.use_count() << std::endl;

	
		std::weak_ptr<Foo> otherOther = fooPtr;

		std::cout << otherOther.use_count() << std::endl;
	

	std::cout << fooPtr.use_count() << std::endl;

	std::shared_ptr<Foo> xyz = otherOther.lock();
	
}


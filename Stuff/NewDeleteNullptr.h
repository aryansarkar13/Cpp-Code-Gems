#pragma once

#include <string>
#include <iostream>

//more info on: http://en.cppreference.com/w/cpp/memory/new/operator_new
//TODO: New operator, overloading new etc.

namespace NewDeleteNullptr
{
	void func(int value){ std::cout << value << '\n'; }
	void func(const char* value) { std::cout << value << '\n'; }

	inline void start()
	{
		using namespace std;

		string* a = NULL;
		string* b = nullptr;

		/*NULL was removed for nullptr for several reasons. Mainly:
		func(NULL);
		Which func will be executed? It's both a pointer and an int.
		*/

		//delete have an internal check for null/nullptr.
		delete a;
		delete b;

		/*
		These functions will therefore not crash when initialized properly.
		If you only declare, same code will crash.
		string* c;
		delete c; //crash because c is 0xcccccccccccccc rather than nullptr.
		*/


	}
}
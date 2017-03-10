/*
////////////////////////////////////////////////////////////////////////////////////

This solution was created in order to keep notes about optimisations, tips,
tricks and other various things that could be useful one day. Micro-optimisations
usually isn't necessary in most ways but to be a better programmer, it certainly
wouldn't hurt to know them. I like to believe that it is better to know all the
unnecessary stuff in order to know when *not* to use them. Good code isn't even
the coolest syntax on the block but the one that is exactly what you were looking
for.

////////////////////////////////////////////////////////////////////////////////////
*/




#include <iostream>
#include <string>
using namespace std;

#include "Wheel.h"
#include "Seat.h"

#include "Rectangle.h"
#include "Square.h"

#include "MoveSemantics.h"

#include "lambdaFuncs.h"
#include "bitwise.h"
#include "lookupTable.h"
#include "constexpression.h"

#include <memory>
#include <array>



int main()
{
	//Polymorphism
	{
		Car* s = nullptr;
		Car* w = nullptr;

		s = new Seat();
		w = new Wheel();

		((Seat*)s)->Print();
		((Wheel*)w)->Print();

		delete s;
		delete w;
	}

	//Friend class
	{
		Rectangle rect;
		rect.Print();
		Square square = Square(5, 99);
		cout << "lul: " << square.ReturnX() << endl;
		rect.SetSide(square);
		rect.Print();
	}

	//Smart pointers
	//auto myobj = std::make_unique<MyClass>(constructor_param1, constructor_param2); // C++14
	//auto myobj = std::unique_ptr<MyClass>(new MyClass(constructor_param1, constructor_param2)); // C++11
	{
		auto mySquare = std::make_unique<Square>(5, 101);
		cout << "SmartPointer 1: " << mySquare->ReturnX() << endl;
		//alt.
		std::unique_ptr<Square> mySquare2 = std::make_unique<Square>(5, 102);
		cout << "SmartPointer 2: " << mySquare2->ReturnX() << endl;
		//Shared

		auto mySquare3 = std::make_shared<Square>(5, 103);
		cout << "SharedPointer 3: " << mySquare3->ReturnX() << endl;
		std::shared_ptr<Square> mySquare4 = mySquare3;
		//alt
		cout << "SharedPointer 4: " << mySquare4->ReturnX() << endl;
	}

	//std array
	{
		const int CAP = 5;
		std::array<int, CAP> nummer;
		for (int i = 0; i < CAP; i++)
		{
			nummer[i] = i + 1;
		}
		for (auto i : nummer)
		{
			cout << i << endl;
		}
	}

	//const check
	{
		Wheel wheel;
		wheel.setValue(5);
		cout << "Othervalue" << wheel.getOtherValue() << endl;
	}

	//smart pointers
	{
		unique_ptr<Wheel> carPart(new Wheel());
		carPart->Print();

		shared_ptr<Seat> carPart2(new Seat());
		carPart2->Print();
	}

	//rvalue reference
	{
		int&& i = 42;
		int j = 42;
		//int&& k = j; // wont compile as j isn't a rvalue. it's a lvalue.

		std::vector<int> fillThisVar, fillThisVar2;
		process_copy(fillThisVar); //clumsy
		process_copy(std::move(fillThisVar2)); //ok
		cout << "rvalue: "<< fillThisVar[0] << " " << fillThisVar2[0] << endl;

	}

	//constexpr
	{
		constexpression();
	}

	//Lambda
	{
		lambdaHelloWord();
		lambdaBasicExample();
		lambdaPassParameter();
	}

	//bitoperators
	{
		bitwiseBasic();
	}

	//look up table
	{
		lookupTable();
	}

	system("pause");
	return 0;
}
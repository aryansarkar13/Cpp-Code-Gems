/*
////////////////////////////////////////////////////////////////////////////////////

This solution was created in order to keep notes about optimisations, tips,
tricks and other various things that could be useful one day. Micro-optimisations
usually isn't necessary in most ways but to be a better programmer, it certainly
wouldn't hurt to know them. I like to believe that it is better to know all the
unnecessary stuff in order to know when *not* to use them. Good code isn't the 
coolest syntax on the block but the one that is exactly what you were looking for.

////////////////////////////////////////////////////////////////////////////////////
*/




#include <iostream>
#include <string>
using namespace std;


#include "Polymorphism.h"
#include "STDArray.h"
#include "constExamples.h"
#include "rvaluereference.h"
#include "lambdaFuncs.h"
#include "bitwise.h"
#include "lookupTable.h"
#include "constexpression.h"
#include "constExamples.h"
#include "smartpointers.h"
#include "friends.h"
#include "argumentOrder.h"
#include "Multithreading.h"
#include "PriorityQueue.h"
#include "paradoxPathfinding.h"
#include "Union.h"
#include "Datastructures.h"
#include "Random.h"
#include "StringManipulation.h"
#include "enumenumclass.h"
#include "DebugRelease.h"

#include "TestingHeader.h"

#include "Timer.h"
#include <memory>



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Polymorphism
	{
		Polymorphism::start();
	}

	//Friend class
	{
		Friends::start();
	}

	//Smart pointers
	{
		SmartPointers::start();
	}

	//std array
	{
		StdArray::start();
	}

	//const check
	{
		ConstExamples::start();
	}

	//rvalue reference
	{
		RValueReference::start();
	}

	//constexpr
	{
		ConstExpression::start();
	}

	//Lambda
	{
		Lambda::start();
	}

	//bitoperators
	{
		Bitwise::start();
	}

	//look up table
	{
		LookupTable::start();
	}

	//Other - Argument order.
	{
		Other::ArgumentOrder::start();
	}

	//Multithreading
	{
		Multithreading::start();
	}

	//PriorityQueue
	{
		PriorityQueue::start();
	}

	//Paradox Interactive Path finding
	{
		Paradox::start();
	}

	//Union keyword
	{
		Union::start();
	}

	//DataStructures
	{
		Datastructures::start();
	}

	//Random
	{
		Random::start();
	}
	
	//String manipulation
	{
		StringManipulation::start();
	}

	//enum / enumclass
	{
		EnumEnumclass::start();
	}

	//Debug / Release
	{
		DebugRelease::start();
	}

	//Tests
	{
		TestStart();
	}

	system("pause");
	return 0;
}
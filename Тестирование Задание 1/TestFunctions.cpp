#pragma once
#include <iostream>
#include "extended_array.h"
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

template <typename T1, typename T2>
void AssertEq(T1 valueA, T2 valueB) {
	if (valueA != valueB) {
		std::ostringstream err;
		err << "Assertion failed: " << valueA << " != " << valueB;
		throw std::runtime_error(err.str());
	}
}

template <typename T>
void EmptyTest(ExtArray<T> a) {

	try {
		AssertEq(a.mean(), 0);
		std::cerr << "Mean function is OK" << std::endl;
	}

	catch (std::runtime_error& e) {
		std::cerr << "Mean function is WRONG" << std::endl;
	}


	try {
		AssertEq(a.median(), 0);
		std::cerr << "Median function is OK" << std::endl;
	}

	catch (std::runtime_error& e) {
		std::cerr << "Median function is WRONG" << std::endl;
	}

	try {
		std::pair<double, int> P = a.mode();
		double L = P.first;
		AssertEq(L, 0);
		std::cerr << "Mode function is OK" << std::endl;
	}

	catch (std::runtime_error& e) {
		std::cerr << "Mode function is WRONG" << std::endl;
	}
};

#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include "extended_array.h"
#include <iostream>
#include "TestFunctions.h"
#include <typeinfo>


int main() {
	ExtArray<bool> arr = { 0, 1, 1, 0, 1, 0, 0, 0, 0, 1 };
	ExtArray<bool> arr2 = { true, false, false, false, true, false, true, true, false, true, false, false, false };
	ExtArray<int> arr3 = { 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1 };
	ExtArray<bool> arr4 = { 1, false, 1, 1, true, false, true, true, false, 1 };
	ExtArray<int> arr5 = { 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 5, 0, 1 };
	ExtArray<double> arr6 = { 1.25, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0 };

	
	std::cout << "Check of array 1: " << std::endl;
	
	checkSumTest(arr, 4);

	std::cout << "Check of array 2: " << std::endl;
	checkSumTest(arr2, 5);

	std::cout << "Check of array 3: " << std::endl;
	checkSumTest(arr3, 8);

	std::cout << "Check of array 4: " << std::endl;
	checkSumTest(arr4, 7);

	std::cout << "Check of array 5: " << std::endl;
	checkSumTest(arr5, 11);

	std::cout << "Check of array 6: " << std::endl;
	checkSumTest(arr6, 6.25);
	system("pause");
	return 0;
}
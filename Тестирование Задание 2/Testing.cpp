
#include <iostream>
#include "extended_array.h"
#include "TestFunctions.h"

int main() {
	size_t s;
	while (true) {

		std::cout << "Enter size of array: ";
		std::cin >> s;
		ExtArray<int> a(s);
		meanIntervalTest(a);
		
}
	system("pause");
	return 0;
}
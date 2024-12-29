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



template <typename T>
	double meanInterval(ExtArray<T> a, size_t begin, size_t end) {
		try {
			if (begin < 0 || end < 0 || begin > a._size || end > a._size || begin > end) {
				throw std::invalid_argument("Error!");
			}
			double sum = 0;
			size_t length = end - begin + 1;
			for (size_t i = begin; i <= end; i++)
			{
				sum += a[i];
			}
			return sum / length;
		}
		catch (std::invalid_argument err) {
			std::cerr << "Arguments must not be loner than 0 and bigger than array size. Begin must be loner than end." << std::endl;
		}
	}


	template <typename T1, typename T2>
	void AssertEq(T1 valueA, T2 valueB) {
		if (valueA != valueB) {
			std::ostringstream err;
			err << "Assertion failed: " << valueA << " != " << valueB;
			throw std::runtime_error(err.str());
		}
	}

	//Тестирование функции среднего интервального значения:

	template <typename T>		
	void meanIntervalTest(ExtArray<T> a) {
		//Генерация случайных чисел для заполнения массива:
		std::random_device rand;
		std::default_random_engine generator{ rand() };
		std::uniform_int_distribution<int> randomNumber{ -100, 100 };

		size_t begin{ 0 }, end{ 0 };
		double expect{ 0 }, sum{ 0 };


			for (int i = 0; i < a.size(); i++) {
				a[i] = randomNumber(generator);
			}

			std::cout << "Generated array: ";

			for (int i = 0; i < a.size(); i++) {
				std::cout << a[i] << " ";
			}

			std::cout << std::endl;

			std::cout << "Enter index of begin and end: ";
			std::cin >> begin >> end;
			try {
				if (begin < 0 || end < 0 || begin > a.size() || end > a.size() || begin > end) {
					throw std::invalid_argument("Error!");
				}

				for (int i = begin; i <= end; i++)
				{
					sum += a[i];
				}
				expect = sum / (end - begin + 1);
				std::cout << "Expected value: " << expect << std::endl;
			}

			catch (std::invalid_argument err) {
				std::cerr << "Arguments must not be loner than 0 and bigger than array size. Begin must be loner than end." << std::endl;
			}

			try {
				AssertEq(a.meanInterval(begin, end), expect);
				std::cout << "Calculated by function value: ";
				std::cout << a.meanInterval(begin, end) << std::endl;
				std::cerr << "meanInterval function is OK" << std::endl << std::endl;
			}

			catch (std::runtime_error& e) {
				std::cerr << "meanInterval function is WRONG" << std::endl << std::endl;
			}

			begin = 0; end = 0; expect = 0; sum = 0;
		};

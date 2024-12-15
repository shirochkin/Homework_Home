#include <iostream>
#include <windows.h>
#include "tetragon.h"
#include "shape.h"

	Tetragon::Tetragon() {
		Tetragon::name = "Tetragon";
		Tetragon::numSides = 4;
	};

	Tetragon::Tetragon(int m, int n, int k, int l, int M, int N, int K, int L) {
		Tetragon::name = "Tetragon";
		Tetragon::numSides = 4;
		Tetragon::a = m; Tetragon::b = n; Tetragon::c = k; Tetragon::d = l;
		Tetragon::A = M; Tetragon::B = N; Tetragon::C = K; Tetragon::D = L;
	};

	//Функция вывода на экран значений сторон:
	void Tetragon::getSides() {
		std::cout << "Values of sides: a = " << Tetragon::a << ", b = " << Tetragon::b << ", c = " << Tetragon::c << ", d = " << Tetragon::d << std::endl;
	};

	//Функция вывода на экран значений углов:
	void Tetragon::getAngles() {
		std::cout << "Values of angles: A = " << Tetragon::A << ", B = " << Tetragon::B << ", Tetragon::C = " << Tetragon::C << ", Tetragon::D = " << Tetragon::D << std::endl;
	}

	//Функция печати:
	void Tetragon::toString() {
		Shape::toString();
		Tetragon::getSides();
		Tetragon::getAngles();
		std::cout << std::endl;
	}

	//Функция установки значений сторон:
	void Tetragon::setSides(int m, int n, int k, int l) {
		Tetragon::a = m; Tetragon::b = n; Tetragon::c = k; Tetragon::d = l;
	}

	//Функция установки значений углов:
	void Tetragon::setAngles(int M, int N, int K, int L) {
		Tetragon::A = M; Tetragon::B = N; Tetragon::C = K; Tetragon::D = L;
	}

	//Функция проверки правильности фигуры:
	bool Tetragon::correct() {
		if (Tetragon::numSides == 4 && (Tetragon::A + Tetragon::B + Tetragon::C + Tetragon::D) == 360) {
			return 1;
		}
		else return 0;
	}

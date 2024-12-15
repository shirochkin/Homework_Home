#include <iostream>
#include <windows.h>
#include "Parallelogramm.h"
#include "tetragon.h"
#include "shape.h"

Parallelogramm::Parallelogramm(int m, int n, int k, int l, int M, int N, int K, int L) {
		Parallelogramm::name = "Parallelogramm";
		Parallelogramm::numSides = 4;
		Parallelogramm::setSides(m, n, k, l);
		Parallelogramm::setAngles(M, N, K, L);
	};

	void Parallelogramm::setSides(int seta, int setb, int setc, int setd) {
		if (seta == setc && setb == setd) {
			Parallelogramm::a = seta;
			Parallelogramm::b = setb;
			Parallelogramm::c = setc;
			Parallelogramm::d = setd;
		}
		else throw;
	}

	//Функция проверки правильности фигуры:
	bool Parallelogramm::correct() {
		if (Tetragon::correct() && Parallelogramm::a == Parallelogramm::c && Parallelogramm::b == Parallelogramm::d && Parallelogramm::A == Parallelogramm::C && Parallelogramm::B == Parallelogramm::D) {
			return 1;
		}
		else return 0;
	}

	void Parallelogramm::setAngles(int setA, int setB, int setC, int setD) {
		if (setA == setC && setB == setD) {
			Parallelogramm::A = setA;
			Parallelogramm::B = setB;
			Parallelogramm::C = setC;
			Parallelogramm::D = setD;
		}
		else throw;
	}
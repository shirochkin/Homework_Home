#include <iostream>
#include <windows.h>
#include "Rhomb.h"
#include "tetragon.h"
#include "shape.h"

Rhomb::Rhomb(int m, int n, int k, int l, int M, int N, int K, int L) {
		Rhomb::name = "Rhomb";
		Rhomb::numSides = 4;
		Rhomb::setSides(m, n, k, l);
		Rhomb::setAngles(M, N, K, L);
	};

	//Функция проверки правильности фигуры:
	bool Rhomb::correct() {
		if (Tetragon::correct() && Rhomb::a == Rhomb::b && Rhomb::b == Rhomb::c && Rhomb::c == Rhomb::d && Rhomb::A == Rhomb::C && Rhomb::B == Rhomb::D) {
			return 1;
		}
		else return 0;
	}

	void Rhomb::setSides(int seta, int setb, int setc, int setd) {
		if (seta == setb && setb == setc && setc == setd) {
			Rhomb::a = seta;
			Rhomb::b = setb;
			Rhomb::c = setc;
			Rhomb::d = setd;
		}
		else throw;
	}

	void Rhomb::setAngles(int setA, int setB, int setC, int setD) {
		if (setA == setC && setB == setD) {
			Rhomb::A = setA;
			Rhomb::B = setB;
			Rhomb::C = setC;
			Rhomb::D = setD;
		}
		else throw;
	}
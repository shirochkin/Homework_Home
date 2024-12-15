#include <iostream>
#include <windows.h>
#include "Rect.h"
#include "tetragon.h"
#include "shape.h"


Rect::Rect(int m, int n, int k, int l, int M, int N, int K, int L) {
		Rect::name = "Rectangle";
		Rect::numSides = 4;
		Rect::setSides(m, n, k, l);
		Rect::setAngles(M, N, K, L);
	};

	void Rect::setSides(int seta, int setb, int setc, int setd) {
		if (seta == setc && setb == setd) {
			Rect::a = seta;
			Rect::b = setb;
			Rect::c = setc;
			Rect::d = setd;
		}
		else throw;
	}

	//Функция проверки правильности фигуры:
	bool Rect::correct() {
		if (Tetragon::correct() && Rect::a == Rect::c && Rect::b == Rect::d && Rect::A == Rect::B && Rect::B == Rect::C && Rect::C == Rect::D && Rect::D == 90) {
			return 1;
		}
		else return 0;
	}

	void Rect::setAngles(int setA, int setB, int setC, int setD) {
		if (setA == setB && setB == setC && setC == setD && setD == 90) {
			Rect::A = setA;
			Rect::B = setB;
			Rect::C = setC;
			Rect::D = setD;
		}
		else throw;
	}
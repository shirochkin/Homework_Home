#include <iostream>
#include <windows.h>
#include "SymmetricTriangle.h"
#include "triangle.h"
#include "shape.h"


	SymmetricTriangle::SymmetricTriangle(int m, int n, int k, int M, int N, int K) {
		SymmetricTriangle::name = "SymmetricTriangle";
		SymmetricTriangle::numSides = 3;
		SymmetricTriangle::setSides(m, n, k);
		SymmetricTriangle::setAngles(M, N, K);
	}

	void SymmetricTriangle::setSides(int seta, int setb, int setc) {
		if (seta == setc) {
			SymmetricTriangle::a = seta;
			SymmetricTriangle::b = setb;
			SymmetricTriangle::c = setc;
		}
		else throw;
	}

	//Функция проверки правильности фигуры:
	bool SymmetricTriangle::correct() {
		if (Triangle::correct() && SymmetricTriangle::a == SymmetricTriangle::c &&SymmetricTriangle::A == SymmetricTriangle::C) {
			return 1;
		}
		else return 0;
	}

	void SymmetricTriangle::setAngles(int setA, int setB, int setC) {
		if (setA == setC) {
			SymmetricTriangle::A = setA;
			SymmetricTriangle::B = setB;
			SymmetricTriangle::C = setC;
		}
		else throw;
	}
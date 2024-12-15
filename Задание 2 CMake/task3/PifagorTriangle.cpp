#include <iostream>
#include <windows.h>
#include "PifagorTriangle.h"
#include "triangle.h"
#include "shape.h"



	PifagorTriangle::PifagorTriangle(int m, int n, int k, int M, int N, int K) {
		PifagorTriangle::name = "PifagorTriangle";
		PifagorTriangle::numSides = 3;
		PifagorTriangle::a = m; PifagorTriangle::b = n; PifagorTriangle::c = k;
		PifagorTriangle::setAngles(M, N, K);
	}

	//Функция проверки правильности фигуры:
	bool PifagorTriangle::correct() {
		if (Triangle::correct() && C == 90) {
			return 1;
		}
		else return 0;
}

	void PifagorTriangle::setAngles(int setA, int setB, int setC) {
		if (setC == 90) {
			PifagorTriangle::A = setA;
			PifagorTriangle::B = setB;
			PifagorTriangle::C = setC;
		}
		else throw;
	}
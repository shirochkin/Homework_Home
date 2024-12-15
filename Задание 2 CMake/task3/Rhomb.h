#pragma once
#include "shape.h"
#include "tetragon.h"

class Rhomb : public Tetragon {
public:
	Rhomb(int m, int n, int k, int l, int M, int N, int K, int L);
	//Функция проверки правильности фигуры:
	bool correct();

	void setSides(int seta, int setb, int setc, int setd);

	void setAngles(int setA, int setB, int setC, int setD);
};
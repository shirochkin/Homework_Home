#pragma once
#include "shape.h"
#include "tetragon.h"

class Parallelogramm : public Tetragon {
public:
	Parallelogramm(int m, int n, int k, int l, int M, int N, int K, int L);

	void setSides(int seta, int setb, int setc, int setd);

	//Функция проверки правильности фигуры:
	bool correct();

	void setAngles(int setA, int setB, int setC, int setD);
};
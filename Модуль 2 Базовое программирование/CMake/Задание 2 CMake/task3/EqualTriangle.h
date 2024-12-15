#pragma once
#include "shape.h"
#include "triangle.h"

class EqualTriangle : public Triangle {
public:

	EqualTriangle(int m, int n, int k, int M, int N, int K);

	void setSides(int seta, int setb, int setc);

	//Функция проверки правильности фигуры:
	bool correct();

	void setAngles(int setA, int setB, int setC);
};
#pragma once
#include "shape.h"
#include "triangle.h"

class PifagorTriangle : public Triangle {
public:

	PifagorTriangle(int m, int n, int k, int M, int N, int K);

	//Функция проверки правильности фигуры:
	bool correct();

	void setAngles(int setA, int setB, int setC);
};
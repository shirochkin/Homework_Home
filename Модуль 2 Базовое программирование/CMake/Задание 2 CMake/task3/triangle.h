#pragma once
#include "shape.h"

class Triangle : public Shape {
public:
	Triangle();

	Triangle(int m, int n, int k, int M, int N, int K);

	//Функция проверки правильности фигуры:
	bool correct() override;

	//Функция вывода на экран значений сторон:
	void getSides();

	//Функция вывода на экран значений углов::
	void getAngles();

	//Функция вывода на экран:
	void toString() override;

	//Функция установки значений сторон:
	virtual void setSides(int m, int n, int k);

	//Функция установки значений углов:
	virtual void setAngles(int M, int N, int K);

protected:
	int a, b, c;
	int A, B, C;

};

#pragma once
#include "shape.h"

class Tetragon : public Shape {
public:
	Tetragon();

	Tetragon(int m, int n, int k, int l, int M, int N, int K, int L); 
	
//Функция вывода на экран значений сторон:
	void getSides();

	//Функция вывода на экран значений углов:
	void getAngles();

	//Функция печати:
	void toString() override;

	//Функция установки значений сторон:
	virtual void setSides(int m, int n, int k, int l);

	//Функция установки значений углов:
	virtual void setAngles(int M, int N, int K, int L);

	//Функция проверки правильности фигуры:
	bool correct() override;

protected:
	int a, b, c, d;
	int A, B, C, D;
};

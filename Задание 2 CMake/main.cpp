#include <iostream>
#include <windows.h>
#include "task3/shape.h"
#include "task3/triangle.h"
#include "task3/tetragon.h"
#include "task3/SymmetricTriangle.h"
#include "task3/EqualTriangle.h"
#include "task3/Parallelogramm.h"
#include "task3/Rhomb.h"
#include "task3/Square.h"
#include "task3/Rect.h"
#include "task3/PifagorTriangle.h"


void printInfo(Shape* shape) {
	shape->toString();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Создание объектов:
	Triangle triangle(10, 20, 30, 50, 60, 70);
	PifagorTriangle pifagorTriangle(10, 20, 30, 50, 60, 90);
	SymmetricTriangle symmetricTriangle(10, 20, 10, 50, 60, 50);
	EqualTriangle equalTriangle(30, 30, 30, 60, 60, 60);
	Tetragon tetragon(10, 20, 30, 40, 50, 60, 70, 80);
	Rect rect(10, 20, 10, 20, 90, 90, 90, 90);
	Square square(20, 20, 20, 20, 90, 90, 90, 90);
	Parallelogramm parallelogramm(20, 30, 20, 30, 30, 40, 30, 40);
	Rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);

	//Печать объектов:
	printInfo(&triangle);
	printInfo(&pifagorTriangle);
	printInfo(&symmetricTriangle);
	printInfo(&equalTriangle);
	printInfo(&tetragon);
	printInfo(&rect);
	printInfo(&square);
	printInfo(&parallelogramm);
	printInfo(&rhomb);

	system ("pause");

	return 0;
}
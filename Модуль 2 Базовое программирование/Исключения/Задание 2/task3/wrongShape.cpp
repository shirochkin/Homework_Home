#include <iostream>
#include <windows.h>
#include "wrongShape.h"

const char* wrongNumSides::what () {
	return "������ �������� ������. �������� ���������� ������. ";
}

const char* wrongValueAngles::what() {
	return "������ �������� ������. �������� �������� �����. ";
}

const char* wrongValueSides::what() {
	return "������ �������� ������. �������� �������� ������. ";
}

const char* wrongSumAngles::what() {
	return "������ �������� ������. �������� ����� �����. ";
}
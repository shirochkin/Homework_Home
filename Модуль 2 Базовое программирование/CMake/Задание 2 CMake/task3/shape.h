#pragma once

class Shape {
public:
	std::string name;
	//Установка количества сторон:
	int getNum();

public:
	virtual void toString();
	//Функция проверки правильности фигуры:
	virtual bool correct();

protected:
	int numSides;
};

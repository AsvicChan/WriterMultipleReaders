#include <iostream>
#include "Controller.h"
#include "Reader.h"
#include "Writer.h"

int main()
{
	Controller controller;
	Writer writer(controller);
	Reader reader1(1, controller);
	Reader reader2(2, controller);
	Reader reader3(3, controller);
	Reader reader4(4, controller);
	Reader reader5(5, controller);
	Reader reader6(6, controller);
	Reader reader7(7, controller);
	Reader reader8(8, controller);
	system("pause");
	return 0;
};
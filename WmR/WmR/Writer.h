#pragma once
#include <iostream>
#include <thread>
#include "Controller.h"
#include "Windows.h"

class Writer
{
private:
	
	Controller& controller_;
	void write()
	{
		for (int i = 0; i != 100; ++i)
		{
			controller_.changeValue(i);
			std::cout << "Wrote " << i << ";"<<std::endl;
			Sleep(1000);
		}
	};
	std::thread thread_;

public:

	Writer(Controller& controller) : controller_(controller), thread_(&Writer::write, this)
	{
		
	};

	~Writer()
	{
		thread_.join();
	};
};
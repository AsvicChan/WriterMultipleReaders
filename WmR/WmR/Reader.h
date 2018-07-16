#pragma once
#include <iostream>
#include "Controller.h"
#include <thread>
#include "Windows.h"

class Reader
{
private:
	int id_;
	Controller& controller_;
	void read()
	{
		for (int i = 0; i != 1000000; ++i)
		{
			int n = controller_.getValue();
			std::cout << "Reader " << id_ << " read " << n << ";" << std::endl;
			Sleep(10);
		}
	};
	std::thread thread_;

public:

	Reader(int id, Controller& controller) : controller_(controller), id_(id), thread_(&Reader::read, this)
	{

	};

	~Reader()
	{
		thread_.join();
	};
};
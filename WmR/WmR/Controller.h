#pragma once
#include <condition_variable>
#include <mutex>

class Controller
{
private:
	int value_;
	std::mutex mutex_;
	std::condition_variable cv_;
	bool writing;
public:

	Controller()
	{

	};

	~Controller()
	{

	};

	void changeValue(int newvalue)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		writing = true;
		cv_.notify_all();
		value_ = newvalue;
		writing = false;
		cv_.notify_all();
	};

	int getValue()
	{
		std::unique_lock<std::mutex> lck(mutex_);
		cv_.wait(lck, [this]() {return (!writing); });
		return value_;
	};
};
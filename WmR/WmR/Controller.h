#pragma once
#include <condition_variable>
#include <mutex>

template <typename T>
class Controller
{
private:
	T& value_;
	std::mutex mutex_;
	std::condition_variable cv_;
	bool writing;
public:

	Controller(T& value) : value_(value)
	{

	};

	~Controller()
	{

	};

	void changeValue(T& newvalue)
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
#include "pch.h"
#include <iostream>
#include "Corepch.h"

#include <thread>
#include <mutex>

mutex m;

template<typename T>
class LockGuard
{
public:
	LockGuard(T& m)
	{
		_mutex = &m;
		_mutex->lock();
	}
	~LockGuard()
	{
		_mutex->unlock();
	}
private:
	T* _mutex;
};


int main()
{
	for (int32 i = 0; i < 10000; i++)
	{
		LockGuard<std::mutex> lockGuard(m);

		std::cout << i;
	}

}

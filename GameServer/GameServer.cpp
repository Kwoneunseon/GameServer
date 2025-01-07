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
		//std::lock_guard<std::mutex> lockGuard(m);

		// 당장 lock을 잠그지 않고, 인터페이스만 생성
		std::unique_lock<std::mutex> uniqueLock(m, std::defer_lock);

		// 잠기는 시점을 설정 가능 -> lock_guard와 차이점.
		uniqueLock.lock();

		std::cout << i;
	}

}

#include "pch.h"
#include <iostream>
#include "Corepch.h"

#include <thread>
#include <atomic>
#include <mutex>

#include "AccountManager.h"
#include "UserManager.h"

void func1()
{
	for (int32 i = 0; i < 100; i++)
	{
		AccountManager::Instance()->ProcessLogin();
	}
}

void func2()
{
	for (int32 i = 0; i < 100; i++)
	{
		UserManager::Instance() ->ProcessSave();
	}
}


int main()
{
	std::thread t1(func1);
	std::thread t2(func2);

	t1.join();
	t2.join();

	std::cout << "Jobs Done" << endl;

	//참고 첫번째 방법
	mutex m1;
	mutex m2;

	//알아서 내부적으로 일관적인 순서로 잠궈줌.
	std::lock(m1, m2); // -> m1.lock; m2.lock();

	//adopt_lock : 이미 lock된 상태니까, 나중에 소멸될떄 풀어주기만해라는 의미
	lock_guard<mutex> g1(m1, std::adopt_lock);
	lock_guard<mutex> g1(m2, std::adopt_lock);

	// 참고 두번쨰 방법
	//사이클 체크로 데드락 발생 가능성 체크

	return 0;
}

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

	return 0;
}

#pragma once
#include <mutex>

class Account
{
	//TODO
};


class AccountManager
{
public:
	static AccountManager* Instance()
	{
		static AccountManager instance;
		return &instance;
	}

	Account* GetID(int32 id)
	{
		lock_guard<mutex> guard(_mutex);

		//¹º°¡¸¦ °¡Á®¿È
		return nullptr;
	}

	void ProcessLogin();
private:
	mutex _mutex;

};


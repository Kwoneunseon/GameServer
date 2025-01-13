#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave()
{
	//accountLokc
	Account* account = AccountManager::Instance()->GetID(100);

	//userlock
	lock_guard<mutex> guard(_mutex);


}
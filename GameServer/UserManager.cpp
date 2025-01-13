#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave()
{
	//userlock
	lock_guard<mutex> guard(_mutex);

	//accountLokc
	Account* account = AccountManager::Instance()->GetID(100);


}
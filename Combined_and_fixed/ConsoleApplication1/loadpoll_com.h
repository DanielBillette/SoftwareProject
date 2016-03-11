#pragma once
#include "Command.h"
#include "User.h"
class loadpoll_com :public Command
{
private:
	User *user;
public:
	loadpoll_com(User *newuser)
	{
		user=newuser;
	}
	void  executeCmd()
	{
		user->loadPoll();
	}
};
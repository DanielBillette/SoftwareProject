#pragma once
#include "Command.h"
#include "User.h"
class createpoll_com :public Command
{
private:
	User *user;
public:
	createpoll_com(User *newuser)
	{
		user=newuser;
	}
	void  executeCmd()
	{
		user->createPoll();
	}
};
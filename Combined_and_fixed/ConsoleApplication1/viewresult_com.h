#pragma once
#include "Command.h"
#include "User.h"
class viewresult :public Command
{
private:
	User *user;
public:
	viewresult(User *newuser)
	{
		user=newuser;
	}
	void  executeCmd()
	{
		//call load result
	}
};
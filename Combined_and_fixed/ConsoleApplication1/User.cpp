#include "User.h"


User::User()
{
}


User::~User()
{
}



void User::createPoll()
{
	if(thisPoll.isEmpty())
	{
		thisPoll.createPoll();

		int in;
		cout << "Would you like to save poll? or send? : "; cin >> in;
		
		switch(in)
		{
		case 1:
		savePoll(thisPoll);
		thisPoll.reset();
		break;

		case 2:
		//send this poll
		break;
		}
		
	}
}

void User::loadPoll()
{
	string in;
	cout << "Enter name of file: "; cin >> in;

	thisPoll.loadPoll(in);
}

/*
void User::recievePoll()
{

}
*/

void User::savePoll(Poll poll)
{
	string in;
	cout << "Enter a name: "; cin >> in;
	poll.savePoll(in);
}

void User::sendPoll()
{
	//send poll
	//empty
}

void User::answerPoll()
{
	//answer
	//BRUH
}

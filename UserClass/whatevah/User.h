#pragma once
#include <iostream>
#include <vector>

#include "Poll.h"

using namespace std;

class User : public Poll
{
public:
	User();
	~User();

	void createPoll();
	void loadPoll();
	//void recievePoll();

private:
	void savePoll(Poll poll);
	void sendPoll();
	void answerPoll();

	vector<Poll> savedPolls;
	Poll thisPoll;
};
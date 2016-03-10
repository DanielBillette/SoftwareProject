#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Poll.h"

using namespace std;

class Recipient
{
public:
	Recipient();
	~Recipient();

	void recievePoll();
private:
	Poll myPoll;
};


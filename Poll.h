#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "dataHub.h"

using namespace std;

class Poll
{
public:
	static Poll *getInstance();

	//structure of poll
	vector<string> sQuestion;
	vector<string> sAnswer1;
	vector<bool> sAnswer2;

	//poll funcs
	void createPoll();			//check for multiple answers
	void loadPoll(string name);
	void savePoll();

	//Sends the poll
	void sendPoll(vector<string> q, vector<string> ans1, vector<bool> ans2) { q = sQuestion; ans1 = sAnswer1; ans2 = sAnswer2;}

	//instructor funcs
	void selectRecipients();

	//helper functions
	void printPoll();
	void printRecipients();

private:
	static Poll* instance;
	Poll();
	
	//data types
	string ext;
	bool recievedPoll;

	//list of current instructors
	vector<string> instructorList;

	//list of recipients
	vector<string> myRecipients;
};


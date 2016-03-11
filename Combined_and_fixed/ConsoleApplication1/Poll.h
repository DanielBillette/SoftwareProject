#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "dataHub.h"
#include"Question.h"

using namespace std;

class Poll:public Question
{
public:
	//structure of poll
	vector<string> sQuestion;
	vector<string> sAnswer1;
	vector<bool> sAnswer2;
	Poll() : state(true),ext(".txt") {	instructorList = x.getInstructorsList();

	recievedPoll=false;}
	//poll funcs
	void createPoll();			//check for multiple answers
	void loadPoll(string name);
	void savePoll(string in);

	//Sends the poll
	void sendPoll(vector<string> q, vector<string> ans1, vector<bool> ans2) { q = sQuestion; ans1 = sAnswer1; ans2 = sAnswer2;}

	//instructor funcs
	void selectRecipients();

		bool isEmpty() { return state; }
	void reset() { state = false; }
	//helper functions
	void printPoll();
	void printRecipients();
	dataHub x;

private:

	vector<Question> myPoll;

	//data types
	string ext;
	bool recievedPoll;

	//list of current instructors
	vector<string> instructorList;

	//list of recipients
	vector<string> myRecipients;
	bool state;
};
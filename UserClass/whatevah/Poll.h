#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <istream>
#include <string>

#include "Question.h"

class Poll : public Question
{
public:
	Poll() : state(true) {}
	~Poll() {}

	void createPoll();
	void loadPoll(string name);
	void savePoll(string name);
	bool isEmpty() { return state; }
	void reset() { state = false; }
	void printPolls()
	{
		cout << "--------------------------------------------------------------------------------";
		for(vector<Question>::iterator it = mQuestions.begin(); it != mQuestions.end(); ++it)
			cout << it->getQuestion() << endl;
		cout << "--------------------------------------------------------------------------------";
	}

private:
	vector<Question> mQuestions;
	bool state;
};
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Question
{
public:
	Question() : mAnswer(false) {}
	~Question() {}

	bool isAnswered()
	{
		if(mAnswer)
			return true;
		return false;
	}
	void setQuestion(string question)
	{
		mQuestion = question;
	}
	string getQuestion()
	{
		return mQuestion;
	}
private:
	string mQuestion;
	bool mAnswer;
};
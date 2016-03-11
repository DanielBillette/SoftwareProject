#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Question
{
public:
	Question(){}
	~Question() {}

	void setShortQuestion(string question)
	{
		shortQuestion = question;
	}
	void setMCQuestion(string question)
	{
		MChoiceQuestion = question;
	}
	void setMCoption(vector<string> option)
	{
		Options=option;
	}
	string getShortQuestion()
	{
		return shortQuestion;
	}
	string getMCQuestion()
	{
		return MChoiceQuestion;
	}
	vector<string> getMCoption()
	{
		return Options;
	}
private:
	string shortQuestion;
	string shortasnwer;
	string MChoiceQuestion;
	vector<string> Options;
};
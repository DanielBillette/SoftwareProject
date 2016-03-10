#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Form
{
public:
	Form(int);
	~Form();
	int GetQuestionCount() { return QuestionCount; }
	void AddQuestions();
	void PrintQuestions();
private:
	int NumOfQuestions;
	int QuestionCount;
	struct Questions1
	{
		string Question;
		int NumOptions;
		string MultipleChoiceQs[100];
		bool isMult;
	};
	Questions1 *Questions = nullptr;
};

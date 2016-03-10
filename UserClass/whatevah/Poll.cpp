#include "Poll.h"

void Poll::createPoll()
{
	state = false;

	int in;
	cout << "Enter amount of questions for poll: "; cin >> in;

	for(int i = 0; i < in; i++)
	{
		Question newQuestion;
		string myQuestion;
		cout << "Enter your question: "; cin >> myQuestion;
		newQuestion.setQuestion(myQuestion);
		mQuestions.push_back(newQuestion);
	}
}

void Poll::loadPoll(string name)
{
	state = true;
	string line;

	ifstream myfile(name + ".txt");

	if(myfile.is_open())
	{
		//initialize the myPoll vector with questions in the txt file
		while(getline(myfile, line))
		{
			Question temp;
			temp.setQuestion(line);
			mQuestions.push_back(temp);
		}

		myfile.close();
	}
	else
		cout << "---file not found---";
	printPolls();
}

void Poll::savePoll(string name)
{
	state = false;
	//Creates the new poll file
	ofstream Pollfile(name + ".txt");

	//Loop through the vector and write in the file
	for(vector<Question>::iterator it = mQuestions.begin(); it != mQuestions.end(); ++it)
		Pollfile << it->getQuestion() << endl;

	Pollfile.close();
}
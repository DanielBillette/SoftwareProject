#include "Poll.h"

Poll* Poll::instance = 0;
Poll* Poll::getInstance()
{
	if(!instance)
	{
		instance = new Poll(); return instance;
	}
	else
	{
		return instance;
	}
}

//Initialize any data types
Poll::Poll() :ext(".txt"), 
			instructorList(dataHub::getInstance()->getInstructorsList()),
			recievedPoll(false)
{}

//Poll funcs
void Poll::createPoll()
{
	/*
		string sQuestion;
		string sAnswer1;
		bool * sAnswer2;
	*/
	//Clears the poll for the new one
	myPoll.clear();

	int state;
	string question, answer1;

	//how many multiple choices and short answers
	int mChoice, sAnswers;
	cout << "Enter amount of short answers:	"; cin >> sAnswers; cout << endl;
	for(int i = 0; i < sAnswers; i++)
	{
		sPoll temp;
		cout << "Enter the Question: "; cin >> question;
		cout << "Enter it's answer: "; cin >> answer1;

		//push back
		temp.sQuestion = question;
		temp.sAnswer1 = answer1;
		myPoll.push_back(temp);
	}
	cout << endl;
	for(int i = 0; i < mChoice; i++)
	{
		sPoll temp;
		bool * answers;
		int choices;

		cout << "Enter the Question: "; cin >> question;
		cout << "Enter how many choices: "; cin >> choices;

		for(int j = 0; j < choices; j++) 
			answers = new bool(false);

		temp.sQuestion = question;
		temp.sAnswer2 = answers;
		
	}
	

	//Add question
	

	//Add it to Poll vector
	

	
}
void Poll::loadPoll(string name)
{
	string line;

	ifstream myfile(name + ext);

	if(myfile.is_open())
	{
		//initialize the myPoll vector with questions in the txt file
		while(getline(myfile, line))
		{
			sPoll temp;
			temp.sQuestion = line;
			myPoll.push_back(temp);
		}

		myfile.close();
	}
	else
		cout << "---file not found---";
}
void Poll::savePoll()
{
	string pollName;

	//set name for poll
	cout << "Enter a name for the poll: "; cin >> pollName;

	//Creates the new poll file
	ofstream Pollfile(pollName + ext);

	//Loop through the vector and write in the file
	for(vector<sPoll>::iterator it = myPoll.begin(); it != myPoll.end(); ++it)
		Pollfile << it->sQuestion << endl;

	Pollfile.close();
}

//instructor funcs
void Poll::selectRecipients()
{
	//list the instructors
	cout << "Please choose from the list of instructors:\n\n";
	dataHub::getInstance()->printInstructors();

	//input instructor email
	string email;
	cout << "Enter email: "; cin >> email;

	//find if email is present in the list
	for(vector<string>::iterator it = instructorList.begin(); it != instructorList.end(); ++it)
	{
		//add to recipient list
		if(email == *it)
		{
			myRecipients.push_back(*it);
			break;
		}
	}

	//Error check
	if(email.empty())
		cout << "\nThere are no instructors with that email\n";
	
}

//print funcs
void Poll::printPoll()
{
	cout << "------------------------\n";
	for(vector<sPoll>::iterator it = myPoll.begin(); it != myPoll.end(); ++it)
		cout << "Question: " << it->sQuestion << endl;
	cout << "------------------------\n";
}
void Poll::printRecipients()
{
	cout << "------------------------\n";
	for(vector<string>::iterator it = myRecipients.begin(); it != myRecipients.end(); ++it)
		cout << "Recipient: "<< *it << endl;
	cout << "------------------------\n";
}
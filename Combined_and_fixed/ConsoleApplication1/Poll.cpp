#include "Poll.h"




//Poll funcs



void Poll::createPoll()
{
	/*
		string shortQuestion;
		string sAnswer1;
		bool * sAnswer2;
	*/
	//Clears the poll for the new one
	myPoll.clear();

	string question;

	//how many multiple choices and short answers
	int mChoice, sAnswers;
	cout << "Poll Createion :\n";
	cout << "Enter amount of short answer questions: "; cin >> sAnswers; cout << endl;
	for(int i = 0; i < sAnswers; i++)
	{

		Question temp;

		cout << "Enter the Question: "; 
		cin >> question;

		temp.setShortQuestion(question);
		myPoll.push_back(temp);
	}
	cout << endl;
	cout << "how many multiple choices questions are there?: "; cin >> mChoice; cout << endl;
	for(int i = 0; i < mChoice; i++)
	{
		Question temp;
		string tempQuestion;
		vector<string> Options;
		int choices;

		cout << "Enter the Question: "; 
		cin >> question;
		cout << "Enter how many choices: ";
		cin >> choices;

		for(int j = 0; j < choices; j++)
		{
			cout << "Option " << j+1 << ": ";
			cin >> tempQuestion;
			Options.push_back(tempQuestion);
		}
		temp.setMCQuestion(question);
		temp.setMCoption(Options);
		myPoll.push_back(temp);
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
			Question temp;
			temp.setShortQuestion(line);
			myPoll.push_back(temp);
		}

		myfile.close();
	}
	else
		cout << "---file not found---";
	printPoll();
}

void Poll::savePoll(string name)
{

	//Creates the new poll file
	ofstream Pollfile(name + ext);

	//Loop through the vector and write in the file
	int count = 1;
	for(vector<Question>::iterator it = myPoll.begin(); it != myPoll.end(); ++it)
	{
		if(it->getShortQuestion() != "")
			Pollfile << "Question " << count << ": " << it->getShortQuestion() << endl;
		if(it->getMCQuestion() != "")
		{
			Pollfile << "Question " << count << ": " << it->getMCQuestion() << endl;
			Pollfile << "Options for questions " << count << ": " << endl;
			for(int i = 0; i < it->getMCoption().size(); i++)
			{
				Pollfile << "Option: " << i+1 << ": " << it->getMCoption().at(i) << endl;
			}
		}
		count++;
	}

	Pollfile.close();
	printPoll();

}

//instructor funcs
void Poll::selectRecipients()
{
	system("cls");

	cout << "\nPlease choose from the list of instructors:\n\n";

	x.PrintInstructors();
	instructorList = x.getInstructors();

	int email = 0;

	do
	{
		cout << "Enter the number of the teacher you want: ";
		cin >> email;

		if(email < instructorList.size() && email > 0)
		{
			myRecipients.push_back(instructorList.at(email-1));
		}

		system("cls");

		if(email > instructorList.size() || email < 0)
		{
			cout << "\n\t[\tInvalid input\t]\t\n" << endl;
		}
		else if(email == 0)
		{
			cout << "\n\t[\tRecipient choosing process complete\t]\t\n\n";
		}
		else
		{
			cout << "\n\t[\t" << instructorList.at(email-1) << "added to recipient list\t]\t" << endl << endl;
		}

		x.PrintInstructors();

	} while(email != 0);
	
}

//print funcs
void Poll::printPoll()
{
	cout << "------------------------\n";
	for(vector<Question>::iterator it = myPoll.begin(); it != myPoll.end(); ++it)
		cout << it->getShortQuestion() << endl;
	cout << "------------------------\n";
}

void Poll::printRecipients()
{
	cout << "------------------------\n";
	for(vector<string>::iterator it = myRecipients.begin(); it != myRecipients.end(); ++it)
		cout << "Recipient: "<< *it << endl;
	cout << "------------------------\n";
}
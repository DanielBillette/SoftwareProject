#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Contacts
{
public:
	Contacts()
	{
		initEmails();
	}
	~Contacts();

	void printMyEmails()
	{
		for(vector<string>::iterator it = m_Emails.begin(); it != m_Emails.end(); ++it)
			cout << (*it) << endl;
	}
	void addFriend(string email)
	{
		string newInstructor = email + "@aii.edu";

		m_Emails.push_back(newInstructor);
	}
	void addFriend(vector<string> listOfEmails)
	{
		for(vector<string>::iterator it = listOfEmails.begin(); it != listOfEmails.end(); ++it)
			m_Emails.push_back(*it);
	}

	vector<string> getEmails()
	{
		return m_Emails;
	}

private:
	//initialize emails from constructor
	void initEmails()
	{
		string line;
		ifstream myfile("Instructors.txt");

		if(myfile.is_open())
		{
			while(getline(myfile, line))
				m_Emails.push_back(line);

			myfile.close();
		}
		else
			cout << "Unable to open file";
	}

	//attributes
	vector<string> m_Emails;
};


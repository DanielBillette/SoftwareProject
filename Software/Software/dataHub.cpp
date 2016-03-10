#include "dataHub.h"

dataHub* dataHub::instance = 0;
dataHub* dataHub::getInstance()
{
	if(!instance)
	{
		instance = new dataHub(); return instance;
	}
	else
	{
		return instance;
	}
}

//Initialize the dataHub with a list of current/available instructors
dataHub::dataHub() :ext("@aii.edu")
{
	string line;
	ifstream myfile("Instructors.txt");

	if(myfile.is_open())
	{
		while(getline(myfile, line))
			mInstructors.push_back(line);

		myfile.close();
	}
	else
		cout << "Unable to open file";
}

//Adds list of instructors
void dataHub::updateInstructorsList(vector<string> newData)
{
	vector<string> temp = newData;
	for(vector<string>::iterator it = temp.begin(); it != temp.end(); ++it)
		mInstructors.push_back(*it);
}

//Adds a single instructor
void dataHub::updateInstructorsList(string item)
{
	string newInstructor = item + ext;

	mInstructors.push_back(newInstructor);
}

//Helper functions

//Print
void dataHub::printInstructors()
{
	cout << "------------------------\n";
	for(vector<string>::iterator it = mInstructors.begin(); it != mInstructors.end(); ++it)
		cout << *it << endl;
	cout << "------------------------\n";
}

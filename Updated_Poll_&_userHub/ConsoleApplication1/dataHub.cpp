#include "dataHub.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/////////////////////////////////////////

//CONSTRUCTOR
dataHub::dataHub()
{
	string line;
	ifstream myfile("Instructors.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
			mInstructors.push_back(line);

		myfile.close();
	}
	else 
		cout << "Unable to open file";
}

//Update list of instructors
vector<string> dataHub::updateInstructorsList(vector<string> newData)
{
	//temp.insert(mInstructors.end(), newData.begin(), newData.end());
	for (vector<string>::iterator it = newData.begin(); it != newData.end(); ++it)
	{
		mInstructors.push_back(*it);
	}
	return mInstructors;
}

//OPERATOR OVERLOADING
vector<string> operator+=(vector<string> a, vector<string> b)
{
	vector<string> result;

	result.insert(a.end(), b.begin(), b.end());

	return result;
}

void dataHub::PrintInstructors()
{
  for(int i = 1; i <= mInstructors.size(); i++)
  {
	  cout << i << ": " << mInstructors.at(i-1) << "\t";
	  if(i % 3 == 0) cout << endl;
  }
  cout << endl;
}
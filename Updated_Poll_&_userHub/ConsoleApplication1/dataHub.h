#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class dataHub
{
public:
	//SINGLETON PATTERN
	//Initialize data
	dataHub();
	//Get the list of instructors
	vector<string> getInstructorsList() { return mInstructors; }

	//Update list of instructors
	vector<string> updateInstructorsList(vector<string> newData);

	friend vector<string> operator+=(vector<string> a, vector<string> b);
	vector<string> Instructors;
	void PrintInstructors();
	vector<string> getInstructors() {return mInstructors;}
private:
	//SINGLETON PATTERN
	vector<string> mInstructors;
};

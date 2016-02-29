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
	static dataHub *getInstance();

	//Get the list of instructors
	vector<string> getInstructorsList() { return mInstructors; }

	//Update list of instructors
	vector<string> updateInstructorsList(vector<string> newData);

	friend vector<string> operator+=(vector<string> a, vector<string> b);
private:
	//SINGLETON PATTERN
	static dataHub* instance;
	
	//Initialize data
	dataHub();

	vector<string> mInstructors;
};


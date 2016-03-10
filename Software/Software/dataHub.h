#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class dataHub
{
public:
	static dataHub *getInstance();

	//Get the list of instructors
	vector<string> getInstructorsList() { return mInstructors; }

	//Update instructors
	void updateInstructorsList(vector<string> newData);
	void updateInstructorsList(string item);
	
	//helper functions
	void printInstructors();
private:
	//SINGLETON PATTERN
	static dataHub* instance;
	
	//Initialize data
	dataHub();

	string ext;
	vector<string> mInstructors;
};
#include <iostream>
#include <vector>
#include <string>

#include "dataHub.h"

using namespace std;

//TEST Print
void print(vector<string> v)
{
	vector<string>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}
	
}

void ExecuteCmd(string cmd)
{

}
void main()
{
	
	vector<string> test;
	vector<string> newData;
	newData.push_back("AAAAAAAAAAAAAAAAAAAAAAAAAAhfbifbasfbaisbdiasdbhasohdasdjaskdA");
	newData.push_back("BBBBBBBBBBBBBBBBBBBBBpoiasjdoadjnsaodasdasdasdasdaBBBBBB");
	newData.push_back("CCCCCCCCCCCCCCCCCCCCaidjaodsajhodajsdisajdoaisjdasiodjaosidjaCCCCCCC");
	test = dataHub::getInstance()->getInstructorsList();
	print(test);
	test = dataHub::getInstance()->updateInstructorsList(newData);
	cout << endl;
	print(test);

	//string cmd;
	//cout << "Enter a command" << endl;
	//cin >> cmd;








	//stop
	getchar();
}
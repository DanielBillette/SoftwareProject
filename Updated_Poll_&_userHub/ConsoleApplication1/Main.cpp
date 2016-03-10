#include <iostream>
#include <vector>
#include <string>
#include"Poll.h"
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
	Poll x;
	x.createPoll();
	x.selectRecipients();
	x.savePoll();
	/*dataHub x;
	vector<string> test;
	vector<string> newData;
	newData.push_back("AAAAAAAAAAAAAAAAAAAAAAAAAAhfbifbasfbaisbdiasdbhasohdasdjaskdA");
	newData.push_back("BBBBBBBBBBBBBBBBBBBBBpoiasjdoadjnsaodasdasdasdasdaBBBBBB");
	newData.push_back("CCCCCCCCCCCCCCCCCCCCaidjaodsajhodajsdisajdoaisjdasiodjaosidjaCCCCCCC");
	test = x.getInstructorsList();
	print(test);
	test = x.updateInstructorsList(newData);
	cout << endl;
	print(test);*/

	//string cmd;
	//cout << "Enter a command" << endl;
	//cin >> cmd;








	//stop
	getchar();
}
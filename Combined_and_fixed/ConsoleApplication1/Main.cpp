#include <iostream>
#include <vector>
#include <string>
#include"Poll.h"
#include "User.h"
#include "Control.h"
#include "dataHub.h"
#include "createpoll_com.h"
#include "loadpoll_com.h"
#include "viewresult_com.h"

using namespace std;



void main()
{

	User *reza = new User;
	Control *control = new Control;
	createpoll_com *create_poll = new createpoll_com(reza);
	loadpoll_com *load_poll = new loadpoll_com(reza);
	viewresult *view_result = new viewresult(reza);

	cout << "Welcome to the Custom POLL program."<<endl;
	cout << "Choose one of the following options:\n";
	int x=9;
	while(x != 0)
	{
		cout << "Menu:\n";
		cout << "1. Create Poll\n";
		cout << "2. Load Poll\n";
		//cout<<"3. View Result\n";
		cin>>x;
		if(x == 1)
		{
			control->setCommand(create_poll);
			system("cls");
			control->buttonPressed();
		}
		else if(x == 2)
		{
			control->setCommand(load_poll);
			system("cls");
			control->buttonPressed();
		}
	}
	//stop
	getchar();
	getchar();
	getchar();
}
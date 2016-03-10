#include <iostream>
#include <fstream>
#include <string>
#include "Form.h"
using namespace std;

void PrintEmails();
void SelectTeachers();
void ChooseRecipients();
int CreateForm();
void Transition();
string Teachers[100];


int main()
{
	Form form(CreateForm());
	form.AddQuestions();
	form.PrintQuestions();
	Transition();
	ChooseRecipients();
}

void Transition()
{
	system("cls");
	cout << "Next, choose who you would like to send the form to: \n\n";
}

int CreateForm()
{
	int NumOfQuestions;
	cout << "First, create a form.\n"
		<< "How many questions would you like on your form?: ";
	cin >> NumOfQuestions;
	return NumOfQuestions;
}

void ChooseRecipients()
{
	string line;
	int count = 0;
	ifstream myfile("Teachers.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			Teachers[count] = line;
			count++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	PrintEmails();
	SelectTeachers();
}

void PrintEmails()
{
	int count = 1;
	while (Teachers[count - 1] != "\0")
	{
		cout << count << ": " << Teachers[count - 1];
		if (count % 3 == 0)
		{
			cout << endl;
		}
		else
		{
			cout << "\t";
		}
		count++;
	}
}

void SelectTeachers()
{
	int UserInput = 1;
	ofstream myfile("Recipients.txt");
	while (UserInput != 0)
	{
		cout << "\n(0 to finish) Choose a recipient: ";
		cin >> UserInput;
		if (myfile.is_open())
		{
			if (UserInput == 0)
			{
				cout << "\n\t[\tRecipients saved to file 'Recipients.txt'\t]\t\n\n";
			}
			else
			{
				myfile << Teachers[UserInput - 1] << endl;
				cout << "\n\t[\t" << Teachers[UserInput - 1] << " added to recipients list" << "\t]\t" << endl;
			}
		}
		else cout << "Unable to open file";
	}
	myfile.close();
}


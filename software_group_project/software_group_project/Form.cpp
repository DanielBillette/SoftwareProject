
#include "Form.h"
using namespace std;

Form::Form(int num)
{
	NumOfQuestions = num;
	Questions = new Questions1[num];
}


Form::~Form()
{
}

void Form::AddQuestions()
{
	int NumOfOptions;
	bool IsMC = false;
	for (int i = 0; i < NumOfQuestions; i++)
	{
		cout << "Enter question " << i + 1 << ": " << endl;
		//getline(cin, Questions[i].Question);
		cin >> Questions[i].Question;
		cout << "Is this question multiple choice?(0 - no | 1 - yes): ";
		cin >> IsMC;
		if (IsMC)
		{
			cout << "How many choices are there?: ";
			cin >> NumOfOptions;
			Questions[i].NumOptions = NumOfOptions;
			Questions[i].isMult = true;
			for (int j = 0; j < NumOfOptions; j++)
			{
				cout << "Option " << j + 1 << ": ";
				cin >> Questions[i].MultipleChoiceQs[j];
			}
		}
		else
		{
			Questions[i].NumOptions = 0;
			Questions[i].isMult = false;
		}
	}
}

void Form::PrintQuestions()
{
	ofstream myfile("Form.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < NumOfQuestions; i++)
		{
			myfile << i + 1 << ") " << Questions[i].Question << endl;
			if (Questions[i].isMult == true)
			{
				myfile << "\tOptions: \n";
				for (int j = 0; j < Questions[i].NumOptions; j++)
				{
					myfile << "\t" << j + 1 << ": " << Questions[i].MultipleChoiceQs[j] << endl;
				}
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}
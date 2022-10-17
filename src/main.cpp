#include <iostream>
#include <string>
#include "tasks.h"



using namespace std;

bool editTask(MyToDo matches1[100], int search1);
bool addToList();
bool getNextItem(MyToDo &mytodo);
bool getByPriority(MyToDo matches[100], int search);
void printToDo();
bool saveToFile();
MyToDo *readData(int*);

int main()
{
	int choice = 0;
	char nextmove = 'y';


	while (nextmove = 'y')
	{
		cout << "This will keep of the things you need to do!" << endl;
		cout << "What would you like to do?" << endl;
		cout << "1. Add to my to do list" << endl;
		cout << "2. Display the next item in my list" << endl;
		cout << "3. Search for activites of a certain priority" << endl;
		cout << "4. Print out my whole list" << endl;
		cout << "5. Save to file" << endl;
		cout << "6. Load from file" << endl;
		cout << "7. Edit task" << endl;

		cin >> choice;

		if (choice == 1)
		{

			addToList();
		}
		else if (choice == 2)
		{

			MyToDo y;

			getNextItem(y);

		
			cout <<"Description: " << y.description << endl;
			cout << "Priority :" << y.priority << endl;
			cout << "Due Date :" << y.dueDate << endl;
			

		}
		else if (choice == 3)
		{
			MyToDo matches[100];
			int search = 0;

			cout << "Enter a priority level to search for 1-5" << endl;
			cin >> search;

			getByPriority(&matches[100], search);
		}
		else if (choice == 4)
		{

			printToDo();
		}
		else if (choice == 5)
		{
			cout << "Save to File" << endl;
			saveToFile();
		}
		else if (choice == 6)
		{
			cout << "Load From File" << endl;
			int total=0;
			readData(&total);
		}
		else if (choice == 7)
		{
			MyToDo matches[100];
			int search = 0;

			cout << "Enter a priority level to search for 1-5" << endl;
			cin >> search;

			editTask(&matches[100], search);
		}
		else
		{
			cout << "That was an incorrect choice!" << endl;
		}
		cout << "would you like to keep playing? y for YES" << endl;
		cin >> nextmove;

	}

	cout << "Good job keeping yourself on schedule!" << endl;
	return 0;

}

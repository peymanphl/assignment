#include <iostream>
#include <string>
#include "tasks.h"
#include <fstream>

using namespace std;
struct MyToDo ToDoList[100];



bool addToList()
{


	if (listSize < 101)
	{


		MyToDo y;

		cout << "what is the description of the activity?" << endl;
		cin.ignore();
		cin.getline( y.description, 20);
		cout << "how urgent is this? rank 1-5. 1 for not really important, 5 for very important" << endl;
		cin >> y.priority;
		cout << "when is the due date? is day/month format" << endl;
		
		cin.ignore();
		cin.getline( y.dueDate, 20);

		cout << "is it completted ? y or n" << endl;
		char c;
		c=getchar();
		if (c == 'y')
			y.completed=true;
		else 
			y.completed=false;


		ToDoList[listSize] = y;
		listSize++;
		return true;
	}
	else
	{
		return false;
	}

}
bool getNextItem(MyToDo &mytodo)
{
	if (listSize == 0)
	{

		return false;
	}
	else if (listSize < positionInList)
	{
		positionInList = 0;
		mytodo = ToDoList[positionInList];
		positionInList++;
	}
	else
	{
		mytodo = ToDoList[positionInList];
		positionInList++;

	}
}

bool editTask(MyToDo matches[100], int search)
{
	int count = 0;
	
	for (int i = 0; i < listSize; i++)
	{
		if (ToDoList[i].priority == search)
		{


			cout << "what is the description of the activity?" << endl;
			cin.ignore();
			cin.getline( ToDoList[i].description, 20);
			cout << "how urgent is this? rank 1-5. 1 for not really important, 5 for very important" << endl;
			cin >>  ToDoList[i].priority;
			cout << "when is the due date? is day/month format" << endl;
			
			cin.ignore();
			cin.getline(  ToDoList[i].dueDate, 20);

			cout << "is it completted ? y or n" << endl;
			char c;
			c=getchar();
			if (c == 'y')
				ToDoList[i].completed=true;
			else 
				ToDoList[i].completed=false;

			return true;
		}
	}


		return true;
	
}

bool getByPriority(MyToDo matches[100], int search)
{
	int count = 0;
	
	for (int i = 0; i < listSize; i++)
	{
		if (ToDoList[i].priority == search)
		{
			matches[count] = ToDoList[i];
	
			cout <<"describtion"<< endl;   
			printf(ToDoList[i].description);   
			cout <<"priority"<< endl;   
			cout << ToDoList[i].priority<<endl;   
			cout <<"Due Date"<< endl;   
			printf(ToDoList[i].dueDate);   
			cout << endl;   

			cout <<"is the task completed?"<< ToDoList[i].completed << endl;   
			return true;
			count++;
		}
	}


		return true;
	
}
void printToDo()
{

	for (int i = 0; i < listSize; i++)
	{
		
	
		cout << "describtion :" << endl;
		printf(ToDoList[i].description);   
		cout << endl;   
		cout << "priotity :" << endl;
		cout << ToDoList[i].priority<<endl;   
		cout << "Due date :" << endl;
		printf(ToDoList[i].dueDate);   
		cout << endl;   
		cout <<"is the task completed? ";  
		if (ToDoList[i].completed == true )

			cout <<"yes"<< endl;  
		else 

			cout <<"no"<< endl;  
		cout << endl;   
		cout << "next task" << endl;
	}
}

bool saveToFile()
{
/*	std::fstream file;
	file.open ("test.txt", ios::out);
	if(file)
	{

		file.fwrite((char*)ToDoList,sizeof(MyToDo));
	}
	else
	cout <<"Error opening the file!\n";
	file.close();
*/
	FILE *file;
  
  	// attempt to open the file with name filename, in 'write to binary file mode'
  	file = fopen("test.txt", "wb");
  
  	// return false if there was an error opening the file
  	if (file == NULL) return false;
  
  	// write the total number of structs in the array to the file, return false 
  	// if the function fails to write the data successfully
  	if (fwrite(&listSize, sizeof(int), 1, file) != 1)
    		return false;
  
  	// write the structs in the array to the file, return false if the function 
  	// fails to write the data successfully
  	if (fwrite((char*)ToDoList, sizeof(MyToDo), listSize, file) != listSize)
    		return false;
  
  	// close access to the file, return false if this fails
  	if (fclose(file) == EOF) return false; 
  
  	// if everything is successful return true
  	return true;
}



MyToDo *readData(int *total)
{
  	FILE *file;
  
  	// open the file with name filename in 'read a binary file mode'
  	file = fopen("test.txt", "rb");
  
  	// if fopen() failed to open the file, return NULL 
  	if (file == NULL) return NULL;
  

  	// read the total number of Student struct data records stored in the file 
  	// into the total pointer parameter
  
  	if (fread(total, sizeof(int), 1, file) != 1) 
    	return NULL;


  	listSize=*total;  

        fread(ToDoList, sizeof(MyToDo), *total, file); 
  
  	// read the data from the file into the block of memory we have allocated, 
  	// return NULL if the read was unsuccessful and free the dynamically allocated
  	// memory to prevent a memory leak

	

  	// close the file, if this is unsuccessful free the dynamically allocated 
  	// memory to prevent a memory leak and return NULL 
  	if (fclose(file) == EOF) 
  	{
    	return NULL;
  	}
	return NULL;  
}


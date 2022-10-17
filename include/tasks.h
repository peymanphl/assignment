#ifndef TODO
#define TODO


using std::string;
using std::int16_t;

static int positionInList = 0;
static int listSize = 0;

struct MyToDo
{
	char  description[20];
	int priority;
	char dueDate[20];
	bool completed;

};

#endif 

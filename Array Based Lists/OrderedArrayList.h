#ifndef Test1
#define Test1

#include "../../std_lib_facilites.h"
#include "ArrayList.h"

class orderedArrayListType : public arrayListType
{
public:
	//constructor
	orderedArrayListType(int max = 100);

	void insertAt(int position, int item);
	void insertEnd(int item);
	void replaceAt(int position, int item);
	int seqSearch(int item);
	void remove(int item);
	void insert(int item);

};

#endif Test1
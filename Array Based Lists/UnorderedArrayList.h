#ifndef Test2
#define Test2

#include "ArrayList.h"

class unordereArrayListType : public arrayListType
{
public:
	//constructor
	unordereArrayListType(int max = 100);

	void insertAt(int position, int item);
	void insertEnd(int item);
	void replaceAt(int position, int item);
	int seqSearch(int item);
	void remove(int item);

};

#endif Test2
#ifndef Test
#define Test

class arrayListType
{
public:
	//constructors
	arrayListType(int max = 100);
	arrayListType(const arrayListType& obj); //copy constructor

	//destructor
	virtual ~arrayListType();

	// Non virtual functions
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	int getMaxLength() const;
	void print() const;
	void clearList();
	bool isSameItem(int position, int item) const;

	void removeAt(int position);
	void retrieveAt(int position, int& value) const;

	// Pure virtual functions
	virtual void insertAt(int position, int item) = 0;
	virtual void insertEnd(int item) = 0;
	virtual void replaceAt(int position, int item) = 0;
	virtual int seqSearch(int item) = 0;
	virtual void remove(int item) = 0;


protected:  // can be directly accessed by the derived classes
	int* list; // point to a dynamic array to store data;
	int length;
	int maxSize;
};
#endif Test

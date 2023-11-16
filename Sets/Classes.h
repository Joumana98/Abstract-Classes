#ifndef Test-H
#define Test-H

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

	int retrieveAt(int position) const;

	// Pure virtual functions
	virtual void insertAt(int position, int item) = 0;
	virtual void insertEnd(int item) = 0;
	virtual void replaceAt(int position, int item) = 0;
	virtual int seqSearch(int item) = 0;
	virtual void removeAt(int position) = 0;
	virtual void remove(int item) = 0;
	virtual void removeAll(int item) = 0;
	virtual int min() = 0;
	virtual int max() = 0;


protected:  // can be directly accessed by the derived classes
	int* list; // point to a dynamic array to store data;
	int length;
	int maxSize;
};

//-------------------------------------------------------------------------------------------------------

class unordereArrayListType : public arrayListType
{
public:
	//constructor
	unordereArrayListType(int max = 100);

	void insertAt(int position, int item);
	void insertEnd(int item);
	void replaceAt(int position, int item);
	int seqSearch(int item);
	void removeAt(int position);
	void remove(int item);
	void removeAll(int item);
	int min();
	int max();

};

class orderedArrayListType : public arrayListType
{
public:
	//constructor
	orderedArrayListType(int max = 100);

	void insertAt(int position, int item);
	void insertEnd(int item);
	void replaceAt(int position, int item);
	int seqSearch(int item);
	void removeAt(int position);
	void remove(int item);
	void removeAll(int item);
	void insert(int item);
	int min();
	int max();

};

class unorderedSetType : public unordereArrayListType
{
public:
	// constructor
	unorderedSetType(int max = 100);

	void insertAt(int position, int item);
	void insertEnd(int item);
	void replaceAt(int position, int item);

};

class orderedSetType : public orderedArrayListType
{
public:
	// constructor
	orderedSetType(int max = 100);

	void replaceAt(int position, int item);
	void insertAt(int position, int item);
	void insertEnd(int item);
	void insert(int item);

};


#endif Test-H

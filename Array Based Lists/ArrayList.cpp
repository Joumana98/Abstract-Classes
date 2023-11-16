#include "ArrayList.h"

arrayListType::arrayListType(int max)
{
	//set maxSize
	if (max <= 0)
		maxSize = 100;
	else
		maxSize = max;

	// create dynamic array
	list = new int[maxSize];

	// set length
	length = 0;
}

//copy constructor
arrayListType::arrayListType(const arrayListType& obj)
{
	maxSize = obj.maxSize;
	length = obj.length;

	list = new int[maxSize];

	for (int i = 0; i < length; i++)
		list[i] = obj.list[i];

}

arrayListType::~arrayListType()
{
	delete[] list;
}

bool arrayListType::isEmpty() const
{
	return (length == 0);
}

bool arrayListType::isFull() const
{
	return (length == maxSize);
}

int arrayListType::getLength() const
{
	return length;
}

int arrayListType::getMaxLength() const
{
	return maxSize;
}

void arrayListType::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}
void arrayListType::clearList()
{
	length = 0;
}
bool arrayListType::isSameItem(int position, int item) const
{
	if (position < 0 || position >= length)
	{
		cout << "The index of the item to compare is out of range." << endl;
		return false;
	}
	else
		return (list[position] == item);
}

void arrayListType::removeAt(int position)
{
	if (position < 0 || position >= length)
	{
		cout << "The index of the item to remove is out of range." << endl;
		return;
	}

	// shift the items to the right

	for (int i = position; i < length - 1; i++)
		list[i] = list[i + 1];
	length--;
}

void arrayListType::retrieveAt(int position, int& value) const
{
	if (position < 0 || position >= length)
	{
		cout << "The index of the item to retrieve is out of range." << endl;
		return;
	}
	value = list[position];

}

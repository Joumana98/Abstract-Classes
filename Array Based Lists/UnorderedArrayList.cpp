#include "UnorderedArrayList.h"

unordereArrayListType::unordereArrayListType(int max) : arrayListType(max)
{

}

void unordereArrayListType::insertEnd(int item)
{
	if (length == maxSize)
	{
		cout << "Cannot insert a new element. The list is full." << endl;
		return;
	}
	list[length] = item;
	length++;

}

void unordereArrayListType::insertAt(int position, int item)
{
	if (position < 0 || position >= maxSize)
	{
		cout << "The position of the item to insert is out of range." << endl;
		return;
	}

	if (length == maxSize)
	{
		cout << "Cannot insert a new element. The list is full." << endl;
		return;
	}

	if (position == maxSize - 1)
		insertEnd(item);
	else
	{
		// make space of the new item
		for (int i = length; i > position; i--)
			list[i] = list[i - 1];
		list[position] = item;
		length++;

	}

}

void unordereArrayListType::replaceAt(int position, int item)
{
	if (position < 0 || position >= length)
	{
		cout << "The position of the item to replace is out of range." << endl;
		return;
	}
	list[position] = item;

}
int unordereArrayListType::seqSearch(int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
			return i; //return the first ocurence of the item
	}
	return -1;

}
void unordereArrayListType::unordereArrayListType::remove(int item)
{
	if (seqSearch(item) == -1)
	{
		cout << "The item to remove cannot be found in the list." << endl;
		return;
	}
	// shift the list elements to the right
	removeAt(seqSearch(item));
}
#include "OrderedArrayList.h"


orderedArrayListType::orderedArrayListType(int max) : arrayListType{ max }
{

}

void orderedArrayListType::insertAt(int position, int item)
{
	if (length == maxSize)
	{
		cout << "Cannot insert a new element. Ordered List is full.";
		return;
	}

	if (position < 0 || position >= length)
	{
		cout << "The position of the item to insert is out of range." << endl;
		return;
	}

	if (list[position - 1] > item || list[position + 1] < item)
	{
		cout << "This item cannot be inserted at this position in the ordered list." << endl;
		return;
	}

	// make space for the new element
	for (int i = length; i > position; i--)
		list[i] = list[i - 1];
	list[position] = item;
	length++;


}

void orderedArrayListType::insertEnd(int item)
{
	if (length == maxSize)
	{
		cout << "Cannot insert a new element. Ordered List is full.";
		return;
	}
	if (item < list[length - 1])
	{
		cout << "This item cannot be insert at the end of the ordered list";
		return;
	}
	list[length] = item;
	length++;

}

void orderedArrayListType::insert(int item)
{
	if (length == maxSize)
	{
		cout << "Cannot insert a new element. Ordered List is full.";
		return;
	}
	if (length == 0)
	{
		insertEnd(item);
		return;
	}

	if (item >= list[length - 1])
	{
		insertEnd(item);
		return;
	}

	// find the last element in the list that is greater than item
	int loc;
	for (loc = length - 1; loc >= 0; loc--)
	{
		if (list[loc] < item)
			break;
	}
	loc++;// determine the position in which the new element should be added

	// make space for the new element
	for (int i = length; i > loc; i--)
		list[i] = list[i - 1];
	list[loc] = item;
	length++;

}

void orderedArrayListType::replaceAt(int position, int item)
{
	if (position < 0 || position >= length)
	{
		cout << "The position of the item to replace is out of range." << endl;
		return;
	}

	if (list[position - 1] > item || list[position + 1] < item)
	{
		cout << "This item cannot be placed at this position in the ordered list." << endl;
		return;
	}
	list[position] = item;

}
int orderedArrayListType::seqSearch(int item)
{
	if (item<list[0] || item>list[length - 1])
		return -1;


	int beg = 0, end = length - 1;
	int loc = length / 2;

	bool found = false;
	while (!found && beg != end)
	{
		if (list[loc] == item)
		{
			found = true;
			break;
		}
		if (item > list[loc])
			beg = loc + 1;
		else
			end = loc - 1;
		loc = (beg + end) / 2;
	}
	if (found || list[beg] == item) // if we exit the while loop when beg=end, we shoud check this item as well
		return loc;
	else
		return -1;
}
void orderedArrayListType::remove(int item)
{
	if (seqSearch(item) == -1)
	{
		cout << "The item to remove is not present in the list." << endl;
		return;
	}
	removeAt(seqSearch(item));

}

#include "Classes.h"

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

int arrayListType::retrieveAt(int position) const
{
	assert(!(position < 0 || position >= length));

	return list[position];

}

//--------------------------------------------------------------------------------------------------

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

void unordereArrayListType::removeAt(int position)
{
	if (position < 0 || position >= length)
	{
		cout << "The index of the item to remove is out of range." << endl;
		return;
	}

	list[position] = list[length - 1];// put the last item at the place of the item to be removed
	length--;
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

void unordereArrayListType::removeAll(int item)
{
	if (seqSearch(item) == -1)
	{
		cout << "The item to remove cannot be found in the list." << endl;
		return;
	}

	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			removeAt(i);
			i--; // check the element that replaced the removed element
		}
	}

}

int unordereArrayListType::min()
{
	int min = list[0];
	for (int i = 0; i < length; i++)
	{
		if (list[i] < min)
			min = list[i];
	}
	return min;

}
int unordereArrayListType::max()
{
	int max = list[0];
	for (int i = 0; i < length; i++)
	{
		if (list[i] > max)
			max = list[i];
	}
	return max;
}

//---------------------------------------------------------------------------------------------------------

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

void orderedArrayListType::removeAt(int position)
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


void orderedArrayListType::remove(int item)
{
	if (seqSearch(item) == -1)
	{
		cout << "The item to remove is not present in the list." << endl;
		return;
	}
	removeAt(seqSearch(item));

}

void orderedArrayListType::removeAll(int item)
{
	if (seqSearch(item) == -1)
	{
		cout << "The item to remove is not present in the list." << endl;
		return;
	}
	int index = seqSearch(item);
	while (list[index] == item)
		removeAt(index);

}

int orderedArrayListType::min()
{
	return list[0];
}

int orderedArrayListType::max()
{
	return list[length - 1];
}


//----------------------------------------------------------------------------------------------------------

unorderedSetType::unorderedSetType(int max) :unordereArrayListType(max)
{
}

void unorderedSetType::insertAt(int position, int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The item to insert already exists in the list." << endl;
			return;
		}
	}
	unordereArrayListType::insertAt(position, item);

}
void unorderedSetType::insertEnd(int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The item to insert already exists in the list." << endl;
			return;
		}
	}
	unordereArrayListType::insertEnd(item);

}
void unorderedSetType::replaceAt(int position, int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The replacing item already exists in the list" << endl;
			return;
		}
	}
	unordereArrayListType::replaceAt(position, item);
}

//--------------------------------------------------------------------------------------------------------

orderedSetType::orderedSetType(int max) : orderedArrayListType(max)
{

}

void orderedSetType::replaceAt(int position, int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The replacing item already exists in the list" << endl;
			return;
		}
	}
	orderedArrayListType::replaceAt(position, item);
}

void orderedSetType::insertAt(int position, int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The item to insert already exists in the list." << endl;
			return;
		}
	}
	orderedArrayListType::insertAt(position, item);

}
void orderedSetType::insertEnd(int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The item to insert already exists in the list." << endl;
			return;
		}
	}
	orderedArrayListType::insertEnd(item);

}

void orderedSetType::insert(int item)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			cout << "The item to insert already exists in the list." << endl;
			return;
		}
	}
	orderedArrayListType::insert(item);
}

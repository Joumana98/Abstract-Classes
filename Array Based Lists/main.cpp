#include "../../std_lib_facilites.h"
#include "ArrayList.h"
#include "OrderedArrayList.h"
#include "UnorderedArrayList.h"

int main()
{
	int n;
	cout << "Enter the max number of elements of the unordered list 1:" << endl;
	cin >> n;
	unordereArrayListType list1{ n };
	for (int i = 0; i < n; i++)
		list1.insertEnd(i);
	list1.print();
	list1.remove(5);
	list1.insertAt(3, 0);
	list1.remove(0);
	list1.insertEnd(11);
	list1.print();
	list1.clearList();
	list1.print();
	cout << list1.isEmpty() << endl;

	cout << endl << endl;
	int m;
	cout << "Enter the max number of elements of the ordered list 2:" << endl;
	cin >> m;
	orderedArrayListType list2{ m };
	for (int j = 0; j < m - 1; j++)
		list2.insert(2 * j);
	list2.print();
	list2.insertAt(3, 5);
	list2.print();
	list2.remove(5);
	list2.print();
	cout << list2.seqSearch(16) << endl;

	return 0;
}
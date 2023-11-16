#include "../../std_lib_facilites.h"
#include "Classes.h"
#include <cassert>


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
	list1.print();
	list1.insertEnd(7);
	list1.print();
	cout << list1.retrieveAt(2) << endl;
	list1.removeAt(5);
	list1.print();
	list1.removeAll(7);
	list1.print();
	cout << "Min: " << list1.min() << endl;
	cout << "Max: " << list1.max() << endl;

	cout << endl << endl;
	int m;
	cout << "Enter the max number of elements of the ordered list 2:" << endl;
	cin >> m;
	orderedArrayListType list2{ m };
	for (int j = 0; j < m - 2; j++)
		list2.insert(2 * j);
	list2.print();
	list2.insertAt(3, 5);
	list2.insert(12);
	list2.print();
	list2.remove(5);
	list2.print();
	cout << list2.seqSearch(6) << endl;
	list2.removeAll(12);
	list2.print();
	cout << "Min: " << list2.min() << endl;
	cout << "Max: " << list2.max() << endl;

	cout << endl;
	unorderedSetType set1{ 10 };
	for (int i = 0; i < 10; i++)
		set1.insertEnd(i);
	set1.print();
	set1.insertAt(20, 2);
	set1.replaceAt(5, 11);
	set1.print();

	cout << endl;
	orderedSetType set2{ 10 };
	for (int i = 0; i < 10; i++)
		set2.insertEnd(2 * i);
	set2.print();
	set2.insert(3);
	set2.replaceAt(5, 5);


	return 0;
}
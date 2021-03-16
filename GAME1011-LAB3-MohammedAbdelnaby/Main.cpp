#include <iostream>
#include "simpleVector.h"
#include "SearchVector.h"
#include "SortableVector.h"
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	const int size = 10;
	SortableVector<int> intTable(size);
	SearchableVector<int> intTable2(size);
	SimpleVector<double> doubleTable(size);

	for (int i = 0; i < size; i++)
	{
		intTable[i] = (i * (1 + rand() % 4));
		doubleTable[i] = (i * 2.5);
		intTable2[i] = (i * 2);
	}

	cout << "Simple vector" << endl;
	doubleTable.print();
	doubleTable.push_back(7.6);
	doubleTable.pop_back();
	cout << endl;


	cout << "Searchable vector" << endl;
	int result = intTable2.findItem(12);
	intTable2.print();
	if (result == -1)
	{
		cout << "Cant find the number" << endl;
	}
	else
	{
		cout << "The number is at " << result << endl;
	}
	cout << endl;


	cout << "Sortable vectors" << endl;
	intTable.print();
	cout << "Now sorted" << endl;
	intTable.sort();
	return 0; 
}
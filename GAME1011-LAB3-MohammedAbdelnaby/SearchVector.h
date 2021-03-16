#pragma once
#include "simpleVector.h"
#include <algorithm>

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector(int s) : SimpleVector<T>(s){}
	SearchableVector(SearchableVector& object) : SimpleVector<T>(object) {}
	SearchableVector(SimpleVector<T>& object) : SimpleVector<T>(object) {}
	int findItem(T);

};

template<class T>
int SearchableVector<T>::findItem(T item)
{
	int low = 0;
	int high = this->size() - 1;
	for (int i = 0; i < this->size(); i++)
	{
		int middle = low + (high - low) / 2;
		if (this->operator[](middle - 1) == item)
		{
			return middle;
		}
		if (this->operator[](middle - 1) < item)
		{
			low = middle + 1;
		}
		else
		{
			low = middle - 1;
		}
	}
		return -1;
}

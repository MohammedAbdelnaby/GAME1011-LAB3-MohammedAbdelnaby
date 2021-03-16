#pragma once
#include "simpleVector.h"
#include <algorithm>
using namespace std;

template <class T>
class SortableVector : public SimpleVector<T>
{
public:
	SortableVector(int s) : SimpleVector<T>(s) {}
	SortableVector(SortableVector& object) : SimpleVector<T>(object) {}
	SortableVector(SimpleVector<T>& object) : SimpleVector<T>(object) {}
	void sort();
};

template<class T>
void SortableVector<T>::sort()
{
	for (int i = 0; i < this->size(); ++i)
	{
		for (int j = i; j < this->size(); ++j)
		{
			if (this->operator[](i) > this->operator[](j))
			{
				T temp = this->operator[](i);
				this->operator[](i) = this->operator[](j);
				this->operator[](j) = temp;
			}
		}
	}
	this->print();
}

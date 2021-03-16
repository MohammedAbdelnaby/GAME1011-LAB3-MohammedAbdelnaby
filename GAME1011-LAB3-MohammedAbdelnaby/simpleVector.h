#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class SimpleVector
{
private:
	T* aprt;
	int arraysize;
	void subError() const;
public:
	SimpleVector(int);
	SimpleVector(const SimpleVector&);
	~SimpleVector();
	int size();
	T& operator[](int);
	void print() const;
	void push_back(T item);
	void pop_back();
};

template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: out of rang" << endl;
	exit(0);
}
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraysize = s;
	aprt = new T[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		aprt[i] = T();
	}
}
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& object)
{
	arraysize = object.arraysize;
	aprt = new T[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		aprt[i] = object.aprt[i];
	}
}
template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraysize > 0)
	{
		delete[] aprt;
	}
}
template <class T>
int SimpleVector<T>::size()
{
	return arraysize;
}
template <class T>
T& SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraysize)
	{
		subError();
	}
	return aprt[sub];
}
template <class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraysize; i++)
	{
		cout << aprt[i] << " ";
	}
	cout << endl;
}

template<class T>
void SimpleVector<T>::push_back(T item)
{
	T* temp = new T[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		temp[i] = aprt[i];
	}
	arraysize++;
	delete[] aprt;
	aprt = new T[arraysize];
	for (int i = 0; i < (arraysize - 1); i++)
	{
		aprt[i] = temp[i];
	}
	aprt[arraysize - 1] = item;
	print();
}

template<class T>
void SimpleVector<T>::pop_back()
{
	T* temp = new T[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		temp[i] = aprt[i];
	}
	arraysize--;
	delete[] aprt;
	aprt = new T[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		aprt[i] = temp[i];
	}
	print();
}

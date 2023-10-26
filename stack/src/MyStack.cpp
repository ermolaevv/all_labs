#include "MyStack.h"

template<class T>
inline TStack<T>::TStack(int n)
{
}

template<class T>
TStack<T>::TStack(TStack<T>& stack)
{
}

template<class T>
TStack<T>::~TStack()
{
}

template<class T>
void TStack<T>::Push(T a)
{
}

template<class T>
T TStack<T>::Get()
{
	return T();
}

template<class T>
T TStack<T>::TopView()
{
	return T();
}

template<class T>
int TStack<T>::GetSize()
{
	return 0;
}

template<class T>
int TStack<T>::GetTop()
{
	return 0;
}

template<class T>
bool TStack<T>::IsFull()
{
	return false;
}

template<class T>
bool TStack<T>::IsEmpty()
{
	return false;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& stack)
{
	return *this;
}

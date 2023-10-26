#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>

template <class T>
class TStack {
protected:
	int size;
	int top;
	T* mas;
public:
	TStack(int n = 0);
	TStack(TStack<T>& stack);
	~TStack();

	void Push(T a);
	T Get();
	T TopView();

	int GetSize();
	int GetTop();

	//операторы вводы и выводы

	bool IsFull();
	bool IsEmpty();

	TStack<T>& operator=(const TStack<T>& stack);
};


#endif
#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>

template <class T>
class TStack {
protected:
	size_t size;
	size_t top;
	T* mas;
public:
	TStack(size_t size = 1);
	TStack(TStack<T>& stack);
	~TStack();

	void Push(T a);
	void Pop();
	T TopView();

	size_t GetSize();
	size_t GetTop();

	//операторы вводы и выводы

	bool IsFull();
	bool IsEmpty();

	TStack<T>& operator=(const TStack<T>& stack);
};

#include "../src/MyStack.hpp"

#endif
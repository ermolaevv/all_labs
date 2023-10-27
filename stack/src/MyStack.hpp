#include "MyStack.h"

template<class T>
TStack<T>::TStack(size_t size)
{
	this->size = size;
	this->top = 0;
	this->mas = new T[this->size]();
}

template<class T>
TStack<T>::TStack(TStack<T>& stack)
{
	this->size = stack.size;
	this->top = stack.top;
	this->mas = new T[this->size]();
	std::copy(stack.mas, stack.mas + stack.size, this->mas);
}

template<class T>
TStack<T>::~TStack()
{
	if (this->mas != nullptr) {
		delete[] this->mas;
		this->mas = nullptr;
	}

	this->size = 0;
	this->top = 0;
}

template<class T>
void TStack<T>::Push(T a)
{
	if (this->IsFull())
		throw std::overflow_error("Stack overflow");
	this->mas[this->top++] = a;
}

template<class T>
void TStack<T>::Pop()
{
	if (this->IsEmpty())
		throw std::underflow_error("Stack is empty");
	this->mas[this->top--] = T();
}

template<class T>
T TStack<T>::TopView()
{
	return this->mas[this->top];
}

template<class T>
size_t TStack<T>::GetSize()
{
	return this->size;
}

template<class T>
size_t TStack<T>::GetTop()
{
	return this->top;
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

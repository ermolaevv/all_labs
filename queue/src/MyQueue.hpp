#include "MyQueue.h"

template<class T>
TQueue<T>::TQueue(size_t n): size(n)
{
	if (size == 0)
		throw std::domain_error("Queue size = 0 throws Heap Curruption Error");

	this->ind = 0;
	this->end = this->size;
	this->count = 0;
	this->mas = new T[this->size]();
}

template<class T>
TQueue<T>::TQueue(TQueue<T>& q) noexcept
{
	this->ind = q.ind;
	this->end = q.end;
	this->count = q.count;
	this->size = q.size;
	this->mas = new T[this->size];
	std::copy(q.mas, q.mas + q.size, this->mas);
}

template<class T>
TQueue<T>::~TQueue() noexcept
{
	if (this->mas == nullptr)
		delete[] this->mas;

	this->mas = nullptr;
	this->count = 0;
	this->end = 0;
	this->ind = 0;
}

template<class T>
void TQueue<T>::Push(T element)
{
	if (this->IsFull())
		throw std::logic_error("Queue is full");

	size_t index = (this->ind + this->count++) % this->size;
	this->mas[index] = element;
	this->end = (this->end + 1) % this->size;
}

template<class T>
T TQueue<T>::Get()
{
	if (this->IsEmpty())
		throw std::logic_error("Queue is empty");

	T tmp = this->mas[this->ind];
	this->mas[this->ind] = T();
	this->ind = (this->ind + 1) % this->size;
	this->count--;
	this->end = (this->end + 1) % this->size;
	return tmp;
}

template<class T>
bool TQueue<T>::IsFull() noexcept
{
	return this->count == this->size;
}

template<class T>
bool TQueue<T>::IsEmpty() noexcept
{
	return this->count == 0;
}

// индексация
template<class T>
T& TQueue<T>::operator[](size_t ind) noexcept
{
	return mas[(this->ind + ind) % this->size];
}

template<class T>
const T& TQueue<T>::operator[](size_t ind) const noexcept
{
	return mas[(this->ind + ind) % this->size];
}
// индексация с контролем
template<class T>
T& TQueue<T>::at(size_t ind)
{
	if (ind >= this->size)
		throw std::out_of_range("Index shoud be less then size");
	return mas[(this->ind + ind) % this->size];
}
template<class T>
const T& TQueue<T>::at(size_t ind) const
{
	if (ind >= this->size)
		throw std::out_of_range("Index shoud be less then size");
	return mas[(this->ind + ind) % this->size];
}

template<class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& queue) noexcept
{
	if (this == &queue)
		return *this;

	if (this->size != queue.size) {
		if (this->mas != nullptr)
			delete[] this->mas;

		this->size = queue.size;
		this->mas = new T[this->size]();
	}

	std::copy(queue.mas, queue.mas + queue.size, this->mas);
	this->count = queue.count;
	this->ind = queue.ind;
	this->end = queue.end;

	return *this;
}

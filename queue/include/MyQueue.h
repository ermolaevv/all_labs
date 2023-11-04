#ifndef _MY_QUEUE_
#define _MY_QUEUE_

#include <iostream>

template <class T>
class TQueue {
protected:
	size_t size;
	size_t ind;
	size_t end;
	size_t count;
	T* mas;

public:
	TQueue(size_t n = 1);
	TQueue(TQueue <T>& queue) noexcept;
	~TQueue() noexcept;

	void Push(T element);
	T Get();

	size_t GetCount() noexcept { return this->count; }
	size_t GetSize() noexcept { return this->size; }
	size_t GetInd() noexcept { return this->ind; }
	size_t GetEnd() noexcept { return this->end; }

	bool IsFull() noexcept;
	bool IsEmpty() noexcept;

	T& operator[](size_t ind) noexcept;
	const T& operator[](size_t ind) const noexcept;

	T& at(size_t ind);
	const T& at(size_t ind) const;

	TQueue<T>& operator=(const TQueue<T>& stack) noexcept;


	//операторы вводы и выводы
	friend std::ostream& operator<<(std::ostream& ostr, const TQueue<T>& queue) noexcept {
		for (size_t i = 0; i < queue.size; i++) {
			ostr << i + 1 << ". " << queue.mas[i] << std::endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream& istr, const TQueue<T>& queue) noexcept {
		for (size_t i = 0; i < queue.size; i++) {
			istr >> queue.mas[i];
		}
		return istr;
	}
};

#include "../src/MyQueue.hpp"

#endif
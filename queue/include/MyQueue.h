#ifndef _MY_QUEUE_
#define _MY_QUEUE_

#include <iostream>

template <class T>
class TQueue {
protected:
	int size;
	int ind;
	int end;
	int count;
	T* mas;

public:
	TQueue(int n = 0);
	TQueue(TQueue <T>& q);
	~TQueue();

	void Push(T a);
	T Get();

	bool IsFull();
	bool IsEmpty();

	//операторы вводы и выводы
};



#endif
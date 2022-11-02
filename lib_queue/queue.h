#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H

#include <iostream>
#include <ostream>

template <class T> class Queue;

template <class T>
class Queue{
	int size;
	T* data;
	int top;
	int end;
public:
	Queue() {

	}

	Queue(int _size) {
		_size < 1 ? throw std::string("Negative value") : NULL;
		data = new T[_size];
		size = _size;
		top = 0;
		end = -1;
	}

	void push(T value) {
		isFull() ? (overexposure() ? NULL : throw std::string("Queue is full")) : void();
		end++;
		data[end] = value;
	}

	bool isFull() {
		return end == size - 1;
	}

	bool isEmpty() {
		return end == -1;
	}

	bool overexposure() {
		return (top != 0 ? dataChange() : false);
	}

private:

	bool dataChange() {
		for (int i = 0; i < end - top; i++) {
			data[i] = data[top + i];
		}
		end = end - top;
		top = 0;
		return true;
	}

};

#endif
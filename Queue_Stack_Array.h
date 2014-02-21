#ifndef _QUEUE_STACK_ARRAY_H
#define _QUEUE_STACK_ARRAY_H

#include <algorithm>

using namespace std;

template <class T>
class Stack {
public:
	Stack(int c = 8): _capacity(c), _top(0) {
		_data = new T [_capacity];
	}
	// Stack(const Stack &s) {
	// 	this->_capacity = s._capacity;
	// 	this->_top = s._top;
	// 	_data = new T [capacity()];
	// 	copy(s._data, s._data + _top, this->_data);
	// }
	~Stack() {
		// delete _data;
		// _data = NULL;
		clear();
	}

	int size() {
		return _top;
	}
	int capacity() {
		return _capacity;
	}
	bool isEmpty() {
		return (size() == 0);
	}
	void push(T t) {
		if( size() == capacity() ) {
			expand();
		}	
		*(_data+_top) = t;
		_top++;
	}
	T peep() {
		if (isEmpty()) throw "Stack is Empty";
		else {
			return *(_data+_top-1);
		}
	}
	T pop() {
		if (isEmpty()) throw "Stack is Empty";
		else {
			T temp = *(_data+_top-1);
			_top--;
			return temp;
		}
	}
	void print() {
		for (int i = 0; i < size(); i++) {
			cout << *(_data+i) << " ";
		}
		cout << endl;
	}
	void expand() {
		T* new_data = new T [2*_capacity];
		copy(_data, _data+_top, new_data);
		_data = new_data;
		_capacity = 2*_capacity;
	}

private:
	void clear(int c = 8) {
		// _capacity = c;
		// delete _data;
		// _data = NULL;
		_capacity = c;
		while ( !isEmpty() ) {
        	pop();
        }
	}

	T* _data;
	int _top;
	int _capacity;
};

template <class T>
class MyQueue {
public:
	MyQueue() {}
	// ~MyQueue() {
	// 	_stack_in.clear();
	// 	_stack_out.clear();
	// }

	bool isEmpty() {
		return ((_stack_in.size() + _stack_out.size()) == 0);
	}
	void enqueue(T n) {
		if (_stack_in.size() == 0) {
			swap_stack();
		}
		_stack_in.push(n);
	}
	Stack<T> getStackIn() {
		return _stack_in;
	}
	T dequeue() {
		if (isEmpty()) {
			return 0;
		}
		if (_stack_out.size() == 0) {
			swap_stack();
		}
		return _stack_out.pop();
	}
	void swap_stack() {
		if (isEmpty()) {
			return;
		}
		if (_stack_out.size() == 0) {
			int size = _stack_in.size();
			for (int i = 0; i < size; i++) {
				T n = _stack_in.pop();
				_stack_out.push(n);
			}
		}
		else {
			int size = _stack_out.size();
			for (int i = 0; i < size; i++) {
				T n = _stack_out.pop();
				_stack_in.push(n);
			}	
		}
	}
private:
	Stack<T> _stack_in;
	Stack<T> _stack_out;
};

#endif
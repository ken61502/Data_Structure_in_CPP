/* Array Implementation */
#ifndef _BTREE_H
#define _BTREE_H

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template <class T>
class Node {
public:
	Node(): valid(1) {}
	Node(T d): data(d), valid(1) {}
	T data;
	bool valid;
};

template <class T>
class BTree {
public:
	BTree(int capa = 8): _capacity(capa), _size(0) {
		_node = new Node<T> [_capacity];
	}
	~BTree() {}

	int size() {
		return (_size);
	}
	bool isEmpty() {
		return (_size == 0);
	}
	virtual void push(T t) = 0;
	// {
	// 	Node<T> n(t);
	// 	if(_size == _capacity) {
	// 		expand(2*_capacity);
	// 	}
	// 	for (int i = 0; i < _capacity; i++) {
	// 		if (_node[i].valid) {
	// 			_node[i].data = t;
	// 			_node[i].valid = 0;
	// 			_size++;
	// 			break;
	// 		}
	// 		else continue;
	// 	}
	// }
	friend ostream& operator<<(ostream &stream, const BTree &tree) {
		int level = 1;
		for (int i = 0; i < tree._capacity; i++) {
			if (i <= (pow(2, level) - 2)) {
				if (!tree._node[i].valid)	stream << tree._node[i].data << " ";
			}
			else {
				if (!tree._node[i].valid)	stream << endl << tree._node[i].data << " ";
				level++;
			}
		}
		return stream;
	} 

protected:
	void expand(int new_capacity) {
		if(new_capacity <= _capacity) throw "New capacity is smaller";
		Node<T>* tmp = new Node<T> [new_capacity];
		copy(_node, _node+_capacity, tmp);
		delete [] _node;
		_capacity = new_capacity;
		_node = tmp;
	}
	int parent(const int &c) {
		return ((c/2) - (1 - c%2));
	}
	int leftChild(const int &p) {
		return (p*2 + 1);
	}
	int rightChild(const int &p) {
		return (p*2 + 2);
	}

	Node<T>* _node;
	int _size;
	int _capacity;
};




#endif
#ifndef _HEAP_H
#define _HEAP_H

#include "BTree.h"

enum HeapType {MAX, MIN};

template <class T>
class Heap: public BTree<T> {
public:
	Heap(HeapType t = MAX): _type(t) {}
	~Heap() {}

	void push(T t) {
		if (this->_size == this->_capacity) {
			this->expand(2*this->_capacity);
		}
		int curr = this->_size++;
		int p = this->parent(curr);

		this->_node[curr].data = t; 
		this->_node[curr].valid = false;

		while (p > -1 && pow(-1, int(_type))*(this->_node[p].data) < pow(-1, int(_type))*(this->_node[curr].data)) {
			swap(p, curr);
			curr = p;
			p = this->parent(curr);
		}
	}

	T pop() {
		if (this->isEmpty()) throw "Heap is empty";

		T tmp = this->_node[0].data;
		int curr = --this->_size;
		swap(0, curr);
		this->_node[curr].valid = true;
		curr = 0;
		int l = this->leftChild(curr);
		int r = this->rightChild(curr);
		while(l < this->_size) {
			if(r < this->_size && pow(-1, int(_type))*(this->_node[l].data) < pow(-1, int(_type))*(this->_node[r].data)) {
				l = r;
			}
			if(pow(-1, int(_type))*(this->_node[l].data) < pow(-1, int(_type))*(this->_node[curr].data))	break;
			swap(l, curr);
			curr = l;
			l = this->leftChild(curr);
			r = this->rightChild(curr);
		}
		return tmp;
	}

private:
	void swap(int a, int b) {
		T tmp = this->_node[a].data;
		this->_node[a].data = this->_node[b].data;
		this->_node[b].data = tmp;
	}
	HeapType _type;
};


#endif
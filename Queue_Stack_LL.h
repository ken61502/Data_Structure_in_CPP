template <class T>
class Node {
public:
	Node(T obj) {
		_data = obj;
		_prev = nullptr;
	}
	~Node() {
		_prev = nullptr;
	}
	T getData() {
		return _data;
	}

	Node<T>* getPrev() {
		return _prev;
	}
	void setPrev(Node<T>* prev) {
		_prev = prev;
	}
private:
	T _data;
	Node<T>* _prev;
};

template <class T>
class Stack {
public:
	Stack() {
		_size = 0;
		_top = nullptr;
	}
	~Stack() {
		clear();
	}
	void clear() {
		Node<T>* n = _top;
		while(n != nullptr) {
			Node<T>* temp = n;
			n = n->getPrev();
			delete temp;
		}
	}
	int size() {
		return _size;
	}
	bool isEmpty() {
		return (_top == nullptr);
	}
	void push(T t) {
		if (isEmpty()) {
			_top = new Node<T> (t);
		}
		else {
			Node<T>* temp = _top;
			_top = new Node<T> (t);
			_top->setPrev(temp);
		}
		_size++;
	}
	T peep() {
		if (isEmpty()) throw "Stack is Empty";
		else {
			return _top->getData();
		}
	}
	T pop() {
		if (isEmpty()) throw "Stack is Empty";
		else {
			Node<T> n = *_top;
			_top = _top->getPrev();
			_size--;
			return n.getData();
		}
	}
private:
	int _size;
	Node<T>* _top;
};

template <class T>
class MyQueue {
public:
	MyQueue() {}
	~MyQueue() {
		_stack_in.clear();
		_stack_out.clear();
	}

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

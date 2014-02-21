#include <iostream>
#include "BTree.h"
#include "Heap.h"

using namespace std;

int main() {
	Heap<int> a(MAX);
	
	for (int i = 0; i < 7; i++) {
		a.push(i);	
	}
	cout << a << endl;
	for (int i = 0; i < 7; i++) {
		cout << "POP: " << a.pop() << endl;
		cout << a << endl;	
	}
	return 0;
}
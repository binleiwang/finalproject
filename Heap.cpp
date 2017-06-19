#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

/**Constructors*/
Heap::Heap(int size) {
	for(int i =0; i < size; i++){
		Order O;
		orderHeap.push_back(O);
	}
}
/**Manipulation Procedures*/
void Heap::heapify(vector<Order> orderHeap, int i) {
	int l = left(i), r = right(i);
	int largest = i;
	if (l <= orderHeap.size() && orderHeap[l] > orderHeap[i])
		largest = l;
	else if (r <= orderHeap.size() && orderHeap[r] > orderHeap[i])
		largest = r;
	if (largest != i) {
		swap(orderHeap[i], orderHeap[largest]);
	}
	heapify(orderHeap, largest);
}

void Heap::buildHeap(vector<Order> orderHeap) {
	int n = orderHeap.size();
	for (int i = floor(n / 2); i >= 1; i--) {
		heapify(orderHeap, i);
	}
}
void Heap::heapIncreaseKey(vector<Order> orderHeap, int i, Order O) {
	orderHeap.push_back(O);
	while (i > 1
			&& orderHeap[parent(i)].getPriorityVal()
					< orderHeap[i].getPriorityVal()) {
		swap(orderHeap[i], orderHeap[parent(i)]);
		i = parent(i);
	}
}

// * HeapInsert(A, key)
//    A[Heap_size(A)] = –∞ //make space at end of array for new value
void Heap::heapInsert(vector<Order> orderHeap, Order key){ // insert to heap by date ordered, speed
	heapIncreaseKey(orderHeap, orderHeap.size(), key);
	orderHeap.size()++;
}

void Heap::heapSort(vector<Order> orderHeap){
	int n = orderHeap.size();
	for(int i = n; i >1; i--){
		swap(orderHeap[1], orderHeap[i]);
		orderHeap.size()--;
		heapify(orderHeap,1);
	}
}
/**Additional Functions*/
int Heap::left(int parent) {
	return 2 * parent;
}
int Heap::right(int parent) {
	return 2 * parent + 1;
}
int Heap::parent(int child) {
	return floor(child / 2);
}
void Heap::swap(Order a, Order b) {
	Order temp = a;
	a = b;
	b = temp;
}

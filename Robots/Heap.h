#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

template<class H>
class Heap {
private:
	vector<H > order;
	int size;
	int leftChild(int parent);
	int rightChild(int parent);
	int parent(int child);
	void swap(H & a, H & b);
	void printOrders(vector<H> h);
public:
	Heap();
	int getSize();
	void insert(H newData);
	void showOrder(int index);
	H deleteMax();
	H deleteOrder(int);
	void buildHeap(); //
	void heapIncreaseKey(H & newdata, int i); // maxHeapify
	void heapDecreaseKey(int first, int last); // bubble down?
	void print();
	bool greater();
};
template<class H>
Heap<H>::Heap() {
	size = order.size();
}
template<class H>
void Heap<H>::showOrder(int index) {
	cout << order[index] << endl;
}

template<class H>
int Heap<H>::getSize() {
	return size;
}

template<class H>
int Heap<H>::leftChild(int parent) {
	return 2 * parent + 1;
}

template<class H>
int Heap<H>::rightChild(int parent) {
	return (2 * parent) + 2;
}

template<class H>
int Heap<H>::parent(int child) {
	return (child - 1) / 2;
}
template<class H>
void Heap<H>::swap(H & a, H & b) {
	H temp = a;
	a = b;
	b = temp;
}

template<class H>
void Heap<H>::heapIncreaseKey(H & newData, int i) {
	if (newData >= order[i])
		order[i] = newData;
	while (i > 0 && order[parent(i)] < order[i]) {
		swap(order[i], order[parent(i)]);
		i = parent(i);
	}
}
template<class H>
void Heap<H>::heapDecreaseKey(int root, int last) {
	if (size <= 1) //there is nothing to decrease
		return;
	//finding the larger child to compare with the root
	else {
		int largest, left = leftChild(root), right = rightChild(root);
		if (order[left] == order[right])
			return;
		else if (order[left] < order[right])
			largest = left;
		else
			largest = right;
		if (order[largest] > order[root]) {
			swap(order[largest], order[root]);
			heapDecreaseKey(largest, last);
		}
	}
}

template<class H>
void Heap<H>::insert(H newData) {
	order.push_back(newData);
	heapIncreaseKey(order[size], size);
	++size;
}
//This function is used to delete the root of the heap (highest priority)
//return the info of max node for user to review
template<class H>
H Heap<H>::deleteMax() {
	assert(size!=0);
	int last = size-1;
	H temp = order[0];
	swap(order[0], order[last]);
	heapDecreaseKey(0,last);
	--size;
	buildHeap();
	return temp;
//	assert(size != 0);
//	H temp = order[0];//save for return
//	swap(order[0], order[size - 1]);
//	order.pop_back();
//	heapDecreaseKey(0, size - 1);
//	--size;
//	buildHeap(); // TEST
//	//heapIncreaseKey(order[size-1], size-1);
//	return temp;
}
//This function is used to delete a random Order (which is not processed)
//return the info of pointed node for user to review
template<class H>
H Heap<H>::deleteOrder(int index) {
	assert(size != 0);
	H temp = order[index];
	order[index] = order[size - 1];
	order.pop_back();
	heapIncreaseKey(order[index], index);
	--size;
	buildHeap();
	return temp;
}
template<class H>
void Heap<H>::buildHeap() {
	int n = size;
	for (int i = n / 2; i >= 0; i--) {
		heapIncreaseKey(order[i], i);
	}
}

template<class H>
bool Heap<H>::greater()
{
	H a;
	H b;
	return a > b;
}

template<class H>
void Heap<H>::print() {
	vector<H> h;
	printOrders(h);
}

template<class H>
void Heap<H>::printOrders(vector<H> h) {
	if (size == 0)
		cout << "List is empty";
	h = order;
	//std::sort(h.begin(), h.end(), greater());
	for (unsigned int i = 0; i < h.size(); i++) {
		cout << h[i] << endl;
	}
}

#endif // !HEAP_H

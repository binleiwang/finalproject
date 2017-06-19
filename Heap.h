/*
 * Heap.h
 *
 *  Created on: Jun 12, 2017
 *      Author: kathy
 */

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>
#include <vector>
#include <tgmath.h> //for floor
#include "Order.h"
using namespace std;

class Heap {
private:
	vector<Order> orderHeap;
	/**Manipulation Procedures*/
	void heapify(vector<Order> orderHeap, int i);
	void heapIncreaseKey(vector<Order> orderHeap, int i, Order key);
	/**Additional Functions*/
	int left(int parent);
	int right(int parent);
	int parent(int child);
public:
	/**Constructors*/
	Heap(int size);
	/**Manipulation Procedures*/
	void buildHeap(vector<Order> orderHeap);
	void heapInsert(vector<Order> orderHeap, Order key);
	void heapSort(vector<Order> orderHeap);
	void swap(Order small, Order large);

};
#endif /* HEAP_H_ */


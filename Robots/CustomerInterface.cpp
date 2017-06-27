#include <iostream>
#include "Heap.h"
#include "Robot.h"
using namespace std;

int main() {
	//vector <int > v;
	Heap <int> H;

	H.insert(5);
	H.insert(90);
	H.insert(300);
	H.insert(3);
	H.insert(45);
	H.insert(1000);

	H.printOrders();
//	cout << "the mx order: " << H.deleteMax()<< endl;
//
//	H.printOrders();
//	cout << "the max order: " << H.deleteMax()<< endl;
//	H.printOrders();
//
//	cout << "delete at index 2: "<<H.deleteOrder(2)<<endl;
	//H.printOrders();
	H.insert(47);
	//H.printOrders();
}
	//cout << "count " << H.getSize()<<endl;
	//cout << "order at index 3: " << H.showOrder(3)<<endl;


////	Robot r1("cosmo","3452", 8.80);
////	Robot r2("drone", "23232", 89.00);
////	Robot r3 ("roomba","34343",33.00);
////	Heap <Robot> h;
////	h.insert(r1);
////	h.insert(r2);
////	h.insert(r3);
////	h.printOrders();
//
//
//
//	return 0;
//}

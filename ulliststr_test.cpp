/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;

int main(int argc, char* argv[])
{
	ULListStr* a = new ULListStr();	
	// TESTCASES
	cout << "TEST CASE FOR PUSHBACK IF EMPTY()" << endl;
	cout << "size before push_back: " << a->size() << endl;
	cout << "all elements before pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	a->push_back(to_string(5));
	cout << "PUSHBACK" << endl;
	cout << "size after push_back: " << a->size() << endl;
	cout << "all elements after pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR PUSHBACK WHEN TAIL'S LAST INDEX IS OCCUPIED" << endl;
	a->push_front(to_string(5)); // place one element to index 9
	cout << "size before push_back: " << a->size() << endl;
	cout << "all elements before pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	a->push_back(to_string(8)); // 
	cout << "PUSHBACK" << endl;
	cout << "size after push_back: " << a->size() << endl;
	cout << "all elements after pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR PUSHBACK IF TAIL->LAST < 9 (COMMON CASE)" << endl;
	for(unsigned int i = 0; i < 14; i++){
		a->push_back(to_string(i));
	}
	cout << "size before push_back: " << a->size() << endl;
	cout << "all elements before pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << "PUSHBACK" << endl;
	a->push_back(to_string(8)); 
	cout << "size after push_back: " << a->size() << endl;
	cout << "all elements after pushback: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR POPBACK IF SIZE == 1" << endl;
	a->push_back(to_string(5)); // add one element 
	cout << "size before pop_back: " << a->size() << endl;
	cout << "all elements before pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	a->pop_back();
	cout << "POPBACK" << endl;
	cout << "size after pop_back: " << a->size() << endl;
	cout << "all elements after pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR POPBACK WHERE TAIL HAS ONE ELEMENT IN INDEX 0 AND HEAD != TAIL" << endl;
	for(unsigned int i = 0; i < 11; i++){ // pushback 11 elements -> 2 items total: head is full, tail has one element in 0th index
		a->push_back(to_string(i));
	}
	cout << "size before pop_back: " << a->size() << endl;
	cout << "all elements before pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	a->pop_back();
	cout << "POPBACK" << endl;
	cout << "size after pop_back: " << a->size() << endl;
	cout << "all elements after pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR POPBACK IN STANDARD CASE" << endl;
	for(unsigned int i = 0; i < 6; i++){ // pushback 6 elements
		a->push_back(to_string(i));
	}
	cout << "size before pop_back: " << a->size() << endl;
	cout << "all elements before pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	a->pop_back();
	cout << "POPBACK" << endl;
	cout << "size after pop_back: " << a->size() << endl;
	cout << "all elements after pop_back: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl; 
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR PUSHFRONT IF EMPTY()" << endl;
	cout << "size before push_front: " << a->size() << endl;
	cout << "all elements before push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	a->push_front(to_string(5));
	cout << "PUSHFRONT" << endl;
	cout << "size after push_front: " << a->size() << endl;
	cout << "all elements after push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR PUSHFRONT WHEN HEAD'S 0TH IS OCCUPIED" << endl;
	a->push_back(to_string(5)); // place one element to index 0
	cout << "size before push_front: " << a->size() << endl;
	cout << "all elements before push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	a->push_front(to_string(8)); // 
	cout << "PUSHFRONT" << endl;
	cout << "size after push_front: " << a->size() << endl;
	cout << "all elements after push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR PUSHFRONT IF TAIL->FIRST > 0 (COMMON CASE)" << endl;
	for(unsigned int i = 0; i < 14; i++){
		a->push_front(to_string(i));
	}
	cout << "size before push_front: " << a->size() << endl;
	cout << "all elements before push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << "PUSHFRONT" << endl;
	a->push_front(to_string(8)); 
	cout << "size after push_front: " << a->size() << endl;
	cout << "all elements after push_front: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	a->clear();
	// ------------------------------------------------------
	cout << "TEST CASE FOR BACK AND FRONT" << endl;
	for(unsigned int i = 0; i < 14; i++){
		a->push_front(to_string(i));
	}
	cout << "all elements: ";
	for(unsigned int i = 0; i < a->size(); i++){
		cout << a->get(i) << ' ';
	}
	cout << endl;
	cout << "back element: " << a->back() << endl;
	cout << "front element: " << a->front() << endl;
	a->clear();
	// ------------------------------------------------------
	delete a;
}


#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

void printList(Node* in);


void printList(Node* in){
  if(in == NULL){
    return;
  }
  cout << in->value << ' ';
  printList(in->next);
}

int main(){
  Node* h = new Node(921, nullptr);
  Node* g = new Node(111, h);
  Node* f = new Node(31, g);
  Node* e = new Node(41, f);
  Node* d = new Node(81, e);
  Node* c = new Node(4, d);
  Node* b = new Node(74, c);
  Node* a = new Node(2, b);
  Node*& refa = a;
  
  Node* evens = nullptr;
  Node*& refe = evens;

  Node* odds = nullptr;
  Node*& refo = odds;

  split(refa, refo, refe);
  // split(refa, refo, refe);

  cout << "odds: ";
  printList(odds);
  cout << endl;

  cout << "evens: ";
  printList(evens);
  cout << endl;

  // cout << "A:" << a->next->value << endl;
}


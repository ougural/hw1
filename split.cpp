/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

using namespace std;

#include <iostream>
#include "split.h"
#include <cstddef>

int ctr = 0;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // if(evens == nullptr && odds == nullptr){
  //   if(in->value % 2 == 0){
  //     evens = in;
  //     delete in;
  //     return split(evens, odds, evens);
  //   }
  //   else{
  //     odds = in;
  //     delete in;
  //     return split(odds, odds, evens);
  //   }
  // }
  if(in == nullptr){
    evens = nullptr;
    odds = nullptr;
    return;
  }
  if(in->value % 2 == 0){
    evens = in;
    return split(in->next, odds, evens->next);
  }
  else{
    odds = in;
    return split(in->next, odds->next, evens);
  }
}

/* If you needed a helper function, write it here */


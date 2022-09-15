#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
	// if empty, create new item
  if(empty()){
		Item* added = new Item();
		head_ = added;
		tail_ = added;
	}
	// if last index in tail is occupied, create new tail, place value in index 0
	else if(tail_->last == ARRSIZE){
		Item* added = new Item();
		tail_->next = added;
		Item* temp = tail_;
		tail_ = added;
		tail_->prev = temp;
	}
	// for common case and repeated code 
  tail_->val[tail_->last] = val;
  tail_->last++;
	size_ ++;
}

void ULListStr::pop_back()
{
	// do nothing if empty
  if(empty()){
		return;
	}	
	// if only one element in ulliststr, just clear and return
	else if(size_ == 1){
		clear();
		return;
	}
	// if tail has only one element in index 0, delete tail, change tail
	else if(tail_->last == 1){
		Item* temp = tail_->prev;
		delete tail_;
		tail_ = temp;
		tail_->next = nullptr;
	}
	// common case
	else{
		tail_->last--;
	}
	size_--;
}

void ULListStr::push_front(const std::string& val)
{
	//if empty, create new item
  if(empty()){
		Item* added = new Item();
		tail_ = added;
		head_ = added;
		head_->first = ARRSIZE;
		head_->last = ARRSIZE;
	}
	//if 0th index in head is occupied, create new a new head, place value to the index 9
	else if(head_->first == 0){
		Item* added = new Item();
		Item* temp = head_;
		head_->prev = added;
		head_ = added;
		head_->next = temp;
		head_->first = ARRSIZE;
		head_->last = ARRSIZE;
	}
	// for common case and repeated code 
	head_->first--;
	head_->val[head_->first] = val;
	size_ ++;
}

void ULListStr::pop_front()
{
	// do nothing if empty
	if(empty()){
		return;
	}
	// if only one element in ulliststr, just clear and return
	else if(size_ == 1){
		clear();
		return;
	}
	// if head has only one element in index 9, delete tail, change head
	else if(head_->first == ARRSIZE - 1){
		Item* temp = head_;
		delete head_; 
		head_ = temp->next;
		head_->prev = nullptr;
	}
	// common case
	else{
		head_->first++;
	}
  size_--;
}

std::string const & ULListStr::back() const
{
	if(empty()){
		return nullptr;
	}
  return(tail_->val[tail_->last - 1]);
}

std::string const & ULListStr::front() const
{
	if(empty()){
		return nullptr;
	}
  return(head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	size_t itr = loc; 
	loc = loc + head_->first;
	Item* temp = head_;
  if(itr < size_ && itr >= 0){
		for(unsigned int i = 0; i < loc / 10; i++){
			temp = temp->next;
		}
		return &temp->val[loc % 10];
	}
	else{
		return nullptr;
	}
}
// END YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

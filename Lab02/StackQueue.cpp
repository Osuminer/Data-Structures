// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"


int ArrayBasedStack::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		//TODO
	}


}

ArrayBasedStack::ArrayBasedStack() {
	for (int i = 0; i < 4; i++) {
		tower[i] = 0;
	}
}

bool ArrayBasedStack::isEmpty() const{
	for (int  i = 0; i < 4; i++) {
		if (tower[i] != 0) {
			return false;
		}
	}

	return true;
}

bool ArrayBasedStack::push(const int & val) {

	for (int i = 0; i < 4; i++) {
		if (tower[i] == 0) {
			tower[i] = val;

			return true;
		}

		i++;
	}

	return false;
}

bool ArrayBasedStack::pop() {

	for (int i = 3; i >= 0; i--) {
		if (tower[i] != 0) {
			tower[i] = 0;

			return true;
		}

		i--;
	}

	return false;
}

std::string ArrayBasedStack::toString() const{

}

ArrayBasedStack::~ArrayBasedStack() {
	for (int i = 0; i < 4; i++) {
		tower[i] = 0;
	}
}

// start of ArrayBasedQueue *************************************************


ArrayBasedQueue::ArrayBasedQueue(){
	for( int i = 0; i < 7; i++ ){
		queue[i] = "0";
	}
	head = 0;
	tail = 0;
}

bool ArrayBasedQueue::isEmpty() const{
	for( int i = 0; i < 7; i++ ){
		if( queue[i] != "0" )
			return false;
	}
	return true;
}

bool ArrayBasedQueue::enQueue(const std::string &val){
	std::string hold = this->peekFront();
	if( this-> isEmpty() ){                               
		queue[head] = val;
		tail += 1;
		return true;
	} else {
		queue[tail] = val;
		tail += 1;
		return true;
	}
	return false;
}

bool ArrayBasedQueue::deQueue(){
	std::string hold = this->peekFront();
	if( this-> isEmpty() ){                               
		return false;                                     
	} else {                                              
		queue[head] = "0";                                
		head += 1;
		return true;
	}
}

std::string ArrayBasedQueue::peekFront() const
{
	if (this->isEmpty()){
		throw "ADT is emtpy";
	} else {
		return queue[head];
	}


}

std::string ArrayBasedQueue::toString() const{

}
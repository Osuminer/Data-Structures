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
		stack[i] = 0;
	}
}

bool ArrayBasedStack::isEmpty() const{
	for (int  i = 0; i < 4; i++) {
		if (stack[i] != 0) {
			return false;
		}
	}

	return true;
}

bool ArrayBasedStack::push(const int & val) {

	for (int i = 0; i < 4; i++) {
		if (stack[i] == 0) {
			stack[i] = val;

			return true;
		}

		i++;
	}

	return false;
}

bool ArrayBasedStack::pop() {

	for (int i = 3; i >= 0; i--) {
		if (stack[i] != 0) {
			stack[i] = 0;

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
		stack[i] = 0;
	}
}



std::string ArrayBasedQueue::peekFront() const
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

std::string ArrayBasedQueue::toString() const{

}

bool ArrayBasedQueue::isEmpty() const{
	for( int i = 0; i < 4; i++ ){
		if( queue[i] != 0 )
			return false;
	}
	return true;
}

bool enQueue(const std::string &val){
	int disk = (int) val[0];
	int columnfrom = (int) val[2];
	int columnto = (int) val[4];
	for( int i = 0; i < 4; i++ ){

	}
}

bool deQueue(){

}


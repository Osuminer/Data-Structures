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

bool ArrayBasedQueue::isEmpty() const{
	
}

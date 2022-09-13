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

}

// start of ArrayBasedQueue *************************************************


ArrayBasedQueue::ArrayBasedQueue(){
	for( int i = 0; i < 7; i++ ){
		queue[i] = "0";
	}
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
	if( this-> isEmpty() ){                               //if queue is empty stores as first value in queue
		queue[1] = val;
		return true;
	} else {
		for( int i = 0; i < 7; i++ ){                     // finds first value in queue, then finds first empty 
			if( queue[i] == hold ){                       // slot in the array to store the value
				for(int a = 1; a <= 7-i; a++ ){           // returns true if possible, false if not
					if( queue[(i+a)] == "0" ){
						queue[(i+a)] = val;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool ArrayBasedQueue::deQueue(){
	std::string hold = this->peekFront();
	if( this-> isEmpty() ){                               // if queue is empty returns false
		return false;                                     
	} else {
		for( int i = 0; i < 7; i++ ){                     // searches for first instance of queue and sets cell
			if( queue[i] == hold ){                       // to empty, then returns true 
				queue[i] == "0";
				return true;
			}
		}
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
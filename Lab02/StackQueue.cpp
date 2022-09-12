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

bool ArrayBasedStack::push(const int & val) {

}

ArrayBasedQueue::ArrayBasedQueue(){
	for( int i = 0; i < 4; i++ ){
		queue[i] = 0;
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
		if(queue[i] = 0){
			queue[i];
		}
	}
}

bool deQueue(){

}


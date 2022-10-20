// StackQueues.cpp : Defines the exported functions for the DLL application.
//

#include "StackQueue.h"


template<class T> 
T ArrayBasedStack<T>::peek() const
{
	if (this->isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		for (int i = 3; i >= 0; i--) {
			if (stack[i] != 0) {
				return stack[i];
			}
		}

		return -1;
	}
}

template<class T>
ArrayBasedStack<T>::ArrayBasedStack() {
	for (int i = 0; i < 4; i++) {
		stack[i] = 0;
	}
}

template<class T>
bool ArrayBasedStack<T>::isEmpty() const{
	for (int  i = 3; i >= 0; i--) {
		if (stack[i] != 0) {
			return false;
		}
	}

	return true;
}

template<class T>
bool ArrayBasedStack<T>::push(const int & val) {
	for (int i = 0; i < 4; i++) {
		if (stack[i] == 0) {
			stack[i] = val;

			return true;
		}
	}

	return false;
}

template<class T>
bool ArrayBasedStack<T>::pop() {
	for (int i = 3; i >= 0; i--) {
		if (stack[i] != 0) {
			stack[i] = 0;

			return true;
		}
	}

	return false;
}

template<class T>
std::string ArrayBasedStack<T>::toString() const{
	std::string finalText = "";

	for (int i = 0; i < 4; i++) {
		if (stack[i] != 0) {
		finalText.append(std::to_string(stack[i]));
		finalText.append(" ");
		}
	}

	return finalText;
}

template<class T>
ArrayBasedStack<T>::~ArrayBasedStack() {
	for (int i = 0; i < 4; i++) {
		stack[i] = 0;
	}
}

// start of ArrayBasedQueue *************************************************

template<class T>
ArrayBasedQueue<T>::ArrayBasedQueue(){
	for( int i = 0; i < 7; i++ ){
		queue[i] = "0";
	}
	head = 0;
	tail = 0;
}

template<class T>
bool ArrayBasedQueue<T>::isEmpty() const{
	for( int i = 0; i < 7; i++ ){
		if( queue[i] != "0" )
			return false;
	}
	return true;
}

template<class T>
bool ArrayBasedQueue<T>::enQueue(const T &val){
	if( this-> isEmpty() ){                               
		queue[head] = val;
		tail += 1;
		return true;
	} else {
		T hold = this->peekFront();
		queue[tail] = val;
		tail += 1;
		return true;
	}
	return false;
}

template<class T>
bool ArrayBasedQueue<T>::deQueue(){
	if( this-> isEmpty() ){                               
		return false;                                     
	} else {             
		T hold = this->peekFront();                                 
		queue[head] = "0";                                
		head += 1;
		return true;
	}
}

template<class T>
T ArrayBasedQueue<T>::peekFront() const
{
	if (this->isEmpty()){
		throw "ADT is emtpy";
	} else {
		return queue[head];
	}


}

template<class T>
std::string ArrayBasedQueue<T>::toString() const{
	std::string finalString = "";

	for(int i = 0; i < 7; i++) {
		finalString.append(queue[i] + "\n");
	}

	return finalString;
}

template<class T>
ArrayBasedQueue<T>::~ArrayBasedQueue() {
	for (int i = 0; i < 7; i++) {
		queue[i] = "0";
	}
	head = 0;
	tail = 0;
}
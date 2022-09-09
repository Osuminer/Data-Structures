// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

bool ILinkedList::isEmpty() const
{
	if (m_count == 0) {
		return true;
	} else {
		return false;
	}
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	std::cout << "Deleting node with value " << m_value << std::endl;
	delete m_next;
	//TODO: - hint, you can recursively handle this which would require some code
	// Otherwise you need to delete each node individuall in the owner of the Nodes (i.e. the LinkedList)
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{
	m_tail = m_head;
}
/** Returns true  if list is empty, otherwise true */
// bool PointerBasedLinkedList::isEmpty() const
// {
// 	if (m_head == nullptr) {
// 		return true;
// 	}

// 	return false;
// }
/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{

	Node * newNode = new Node(val);

	if (isEmpty()) {
		m_head = newNode;
		m_tail = newNode;
	} else {
		m_tail->setNext(newNode);
		m_tail = newNode;
	}

	m_count++;

	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{
	Node * curr(m_head);
	Node * prev(m_head);

	int i = 0;

	while (curr->getItem() != val) {
		i++;
		prev = curr;
		curr = curr->getNext();

		if (curr == nullptr) {
			return false;
		}
	}

	if (i == 0) {
		m_head = prev->getNext();
	} else {
		prev->setNext(curr->getNext());
	}

	m_count--;

	return true;
}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	Node * curr(m_head);

	delete curr;

	m_head = nullptr;

	m_count = 0;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";

	Node * curr(m_head);

	while (curr != nullptr) {
		str.append(to_string(curr->getItem()) + " ");
		curr = curr->getNext();
	}

	str.erase(str.find_last_not_of(' ')+1); 
	
	return str;
}

ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0;

	for (int i = 0; i < 10; i++) {
		m_values[i] = 0;
	}
}

// bool ArrayBasedLinkedList::isEmpty() const
// {
// 	if (m_count == 0) {
// 		return true;
// 	} else {
// 		return false;
// 	}
// }
bool ArrayBasedLinkedList::add(int val)
{
	if (m_count < 10) {
		m_values[m_count] = val;
		m_count++;
		return true;
	} else {
		return false;
	}
}
bool ArrayBasedLinkedList::remove(int val)
{
	if (m_count > 0) {
		int i = 0;
		while (m_values[i] != val && i < 10) {
			i++;
		}

		if (i == 10) {
			return false;
		}
		
		m_values[i] = 0;
		m_count--;
		return true;
	} else {
		return false;
	}
}
void ArrayBasedLinkedList::clear()
{
	for (int i = 0; i < 10; i++) {
		m_values[i] = 0;
	}

	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";

	for (int i = 0; i < 10; i++) {
		if (m_values[i] != 0) {
			str.append(to_string(m_values[i]) + " ");
		}
	}

	str.erase(str.find_last_not_of(' ')+1); 

	return str;
}

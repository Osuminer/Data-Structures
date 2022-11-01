#include "PriorityQueue.h"
#include <string>

ArrayBasedPriorityQueue::ArrayBasedPriorityQueue(){}
ArrayBasedPriorityQueue::~ArrayBasedPriorityQueue(){}
void ArrayBasedPriorityQueue::Insert(int num) const{}
void ArrayBasedPriorityQueue::DeQueue() const{}
std::string ArrayBasedPriorityQueue::PrintPriorityQueue() const{}
bool ArrayBasedPriorityQueue::isEmpty() const{
    return m_head == m_tail;
}

HeapBasedPriorityQueue::HeapBasedPriorityQueue(){}
HeapBasedPriorityQueue::~HeapBasedPriorityQueue(){}
void HeapBasedPriorityQueue::Insert(int num) const{}
void HeapBasedPriorityQueue::DeQueue() const{}
std::string HeapBasedPriorityQueue::PrintPriorityQueue() const{}
bool HeapBasedPriorityQueue::isEmpty() const{}
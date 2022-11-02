#include "PriorityQueue.h"
#include <string>

ArrayBasedPriorityQueue::ArrayBasedPriorityQueue(){}
ArrayBasedPriorityQueue::~ArrayBasedPriorityQueue(){
    m_size = 0;
}

void ArrayBasedPriorityQueue::Insert(int num) {
    m_array[m_size] = num;
    
    Sort();

    m_size++;
}

void ArrayBasedPriorityQueue::DeQueue() {
    m_size--;
}

std::string ArrayBasedPriorityQueue::PrintPriorityQueue() const{
    std::string temp = "";

    for (int i = m_size-1; i >= 0; i--) {
        temp.append(std::to_string(m_array[i]) + " ");
    }

    return temp;
}

bool ArrayBasedPriorityQueue::isEmpty() const{
    return m_size == 0;
}

void ArrayBasedPriorityQueue::Sort() {
    int min;
    int temp;

    if (m_size == 1) {
        return;
    }

    for (int i = 0; i < m_size; i++) {
        min = i;

        for (int j = i+1; j <= m_size; j++) {
            if (m_array[j] < m_array[min]) {
                min = j;
            }
        }
        temp = m_array[i];
        m_array[i] = m_array[min];
        m_array[min] = temp;
    }
}

HeapBasedPriorityQueue::HeapBasedPriorityQueue(){}
HeapBasedPriorityQueue::~HeapBasedPriorityQueue(){}
void HeapBasedPriorityQueue::Insert(int num){}
void HeapBasedPriorityQueue::DeQueue() {}
std::string HeapBasedPriorityQueue::PrintPriorityQueue() const{}
bool HeapBasedPriorityQueue::isEmpty() const{}
#include "PriorityQueue.h"
#include "Node.h"
#include <string>
#include <vector>


void Sort(int (&m_array)[], int m_size) {
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

// Array Based -----------------------------------------------------------------------------------------------------

ArrayBasedPriorityQueue::ArrayBasedPriorityQueue(){}

ArrayBasedPriorityQueue::~ArrayBasedPriorityQueue(){
    m_size = 0;
}

void ArrayBasedPriorityQueue::Insert(int num) {
    m_array[m_size] = num;
    
    Sort(m_array, m_size);

    m_size++;
}

void ArrayBasedPriorityQueue::DeQueue() {
    m_size--;
}

std::string ArrayBasedPriorityQueue::PrintPriorityQueue() {
    std::string temp = "";

    for (int i = m_size-1; i >= 0; i--) {
        temp.append(std::to_string(m_array[i]) + " ");
    }

    return temp;
}

bool ArrayBasedPriorityQueue::isEmpty() const{
    return m_size == 0;
}

// Heap Based -----------------------------------------------------------------------------------------------------

HeapBasedPriorityQueue::HeapBasedPriorityQueue(){}
HeapBasedPriorityQueue::~HeapBasedPriorityQueue(){}

void HeapBasedPriorityQueue::Insert(int num){
    m_heap[m_size] = num;

    BubbleUp(m_size);

    m_size++;
}
void HeapBasedPriorityQueue::DeQueue() {

    m_size--;
}

std::string HeapBasedPriorityQueue::PrintPriorityQueue() {
    std::string temp = "";

    for (int i = 0; i < m_size; i++) {
        temp.append(std::to_string(m_heap[i]) + " ");
    }

    return temp;
}

bool HeapBasedPriorityQueue::isEmpty() const{
    return m_size == 0;
}

void HeapBasedPriorityQueue::Swap(int& a, int& b){
    int temp;

    temp = a;
    a = b;
    b = temp;
    }

void HeapBasedPriorityQueue::BubbleUp(int nodeIndex) {
    while (m_heap[nodeIndex] > m_heap[GetParent(nodeIndex)] && nodeIndex > 0) {
        Swap(m_heap[nodeIndex], m_heap[GetParent(nodeIndex)]);

        nodeIndex = GetParent(nodeIndex);
    }
}

int HeapBasedPriorityQueue::GetParent(int nodeIndex) {
    return ((nodeIndex - 1) / 2);
    }

int HeapBasedPriorityQueue::GetLeft(int nodeIndex) {
    return ((2 * nodeIndex) + 1);
    } 

int HeapBasedPriorityQueue::GetRight(int nodeIndex) {
    return ((2 * nodeIndex) + 2);
}
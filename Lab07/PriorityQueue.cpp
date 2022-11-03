#include "PriorityQueue.h"
#include <string>


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
    m_heap[0] = m_heap[m_size-1];
    m_size--;

    BubbleDown(0);
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

void HeapBasedPriorityQueue::BubbleDown(int nodeIndex) {
    int maxIndex = nodeIndex;

    int leftIndex = GetLeft(nodeIndex);
    int rightIndex = GetRight(nodeIndex);

    // If left child node is greater than current max node, then set new max index
    if (leftIndex < m_size && m_heap[leftIndex] > m_heap[maxIndex]) {
        maxIndex = leftIndex;
    }

    // If right child node is greater than current max node, then set new max index
    if (rightIndex < m_size && m_heap[rightIndex] > m_heap[maxIndex]) {
        maxIndex = rightIndex;
    }

    if (nodeIndex != maxIndex) {
        Swap(m_heap[nodeIndex], m_heap[maxIndex]);
        BubbleDown(maxIndex);
    }
}

/// @brief Get index of parent node
/// @param nodeIndex 
/// @return 
int HeapBasedPriorityQueue::GetParent(int nodeIndex) {
    return ((nodeIndex - 1) / 2);
    }

/// @brief Get index of left child node
/// @param nodeIndex 
/// @return 
int HeapBasedPriorityQueue::GetLeft(int nodeIndex) {
    return ((2 * nodeIndex) + 1);
    } 

/// @brief Get index of right child node
/// @param nodeIndex 
/// @return 
int HeapBasedPriorityQueue::GetRight(int nodeIndex) {
    return ((2 * nodeIndex) + 2);
}
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

void Sort(std::vector<int>& v, int m_size) {
    int min;
    int temp;

    if (m_size == 1) {
        return;
    }

    for (int i = 0; i < m_size-1; i++) {
        min = i;

        for (int j = i+1; j < m_size; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
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
    Node<int>* n = new Node(num);

    InOrderSearch(n, m_root);

    m_size++;
}
void HeapBasedPriorityQueue::DeQueue() {

    m_size--;
}

std::string HeapBasedPriorityQueue::PrintPriorityQueue() {
    std::vector<int> v;
    std::string temp = "";

    InOrderSearch(v, m_root);

    Sort(v, m_size);

    for (int i = m_size-1; i >= 0; i--) {
        temp.append(std::to_string(v[i]) + " ");
    }

    return temp;
}

bool HeapBasedPriorityQueue::isEmpty() const{
    return m_size == 0;
}
void HeapBasedPriorityQueue::Swap(){}

bool HeapBasedPriorityQueue::InOrderSearch(Node<int>* n, Node<int>* tempRoot) {
    if (m_size == 0) {
        m_root->SetValue(n->ReturnValue());
        return true;
    }

    if (tempRoot->GetLeftNode() == nullptr) {
        tempRoot->SetLeftNode(n);
        return true;
    }

    if (tempRoot->GetRightNode() == nullptr) {
        tempRoot->SetRightNode(n);
        return true;
    }

    if (InOrderSearch(n, tempRoot->GetLeftNode())) {
        return true;
    }
    if (InOrderSearch(n ,tempRoot->GetRightNode())) {
        return true;
    }
    
    return false;
}

void HeapBasedPriorityQueue::InOrderSearch(std::vector<int>& v, Node<int>* tempRoot) {
    if (tempRoot == nullptr) {
        return;
    }

    if (tempRoot->GetLeftNode() == nullptr) {
        v.push_back(tempRoot->ReturnValue());
        InOrderSearch(v, tempRoot->GetRightNode());
        return;
    } 

    InOrderSearch(v, tempRoot->GetLeftNode());
    v.push_back(tempRoot->ReturnValue());
    InOrderSearch(v, tempRoot->GetRightNode());
    return;
}
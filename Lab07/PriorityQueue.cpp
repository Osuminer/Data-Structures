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

HeapBasedPriorityQueue::HeapBasedPriorityQueue(){}
HeapBasedPriorityQueue::~HeapBasedPriorityQueue(){}
void HeapBasedPriorityQueue::Insert(int num){
    Node<int>* n = new Node(num);

    InOrderSearch(n, m_root);
}
void HeapBasedPriorityQueue::DeQueue() {}
std::string HeapBasedPriorityQueue::PrintPriorityQueue() {
    std::vector<int> v;

    InOrderSearch(v, m_root);

    Sort(v, m_size);
}

bool HeapBasedPriorityQueue::isEmpty() const{
    return m_size == 0;
}
void HeapBasedPriorityQueue::Swap(){}

void HeapBasedPriorityQueue::InOrderSearch(Node<int>* n, Node<int>* tempRoot) {
    if (tempRoot == nullptr) {
        m_root->SetValue(n->ReturnValue());
        return;
    }

    if (tempRoot->GetLeftNode() == nullptr) {
        tempRoot->SetLeftNode(n);
        return;
    }

    if (tempRoot->GetRightNode() == nullptr) {
        tempRoot->SetRightNode(n);
        return;
    }

    InOrderSearch(n, tempRoot->GetLeftNode());
    InOrderSearch(n ,tempRoot->GetRightNode());
    return;
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
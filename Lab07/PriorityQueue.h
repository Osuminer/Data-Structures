#include <string>
#include <vector>
#include "Node.h"

const int SIZE = 500;

class PriorityQueue {
    public:
        virtual void Insert(int) = 0;  
        virtual void DeQueue() = 0;
        virtual std::string PrintPriorityQueue() = 0;
        virtual bool isEmpty() const = 0;

    private:

};

class ArrayBasedPriorityQueue : PriorityQueue {
    public:
        ArrayBasedPriorityQueue(void);
        virtual ~ArrayBasedPriorityQueue();
        void Insert(int) override;
        void DeQueue() override;
        std::string PrintPriorityQueue() override;
        bool isEmpty() const override;

    private:
        int m_array[SIZE];
        int m_size = 0;
};

class HeapBasedPriorityQueue : PriorityQueue{
    public:
        HeapBasedPriorityQueue(void);
        virtual ~HeapBasedPriorityQueue();
        void Insert(int) override;
        void DeQueue() override;
        std::string PrintPriorityQueue() override;
        bool isEmpty() const override;
        void Swap();
        bool InOrderSearch(Node<int>*, Node<int>*);
        void InOrderSearch(std::vector<int>&, Node<int>*);

    private:
        Node<int>* m_root = new Node<int>();
        int m_size = 0;
};
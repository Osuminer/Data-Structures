#include <string>

const int SIZE = 500;

class PriorityQueue {
    public:
        virtual void Insert(int) const = 0;  
        virtual void DeQueue() const = 0;
        virtual std::string PrintPriorityQueue() const = 0;
        virtual bool isEmpty() const = 0;

    private:

};

class ArrayBasedPriorityQueue : PriorityQueue {
    public:
        ArrayBasedPriorityQueue(void);
        virtual ~ArrayBasedPriorityQueue();
        void Insert(int) const override;
        void DeQueue() const override;
        std::string PrintPriorityQueue() const override;
        bool isEmpty() const override;

    private:
        int m_array[SIZE];
        int m_tail = 0;
        int m_head = 0;
};

class HeapBasedPriorityQueue : PriorityQueue{
    public:
        HeapBasedPriorityQueue(void);
        virtual ~HeapBasedPriorityQueue();
        void Insert(int) const override;
        void DeQueue() const override;
        std::string PrintPriorityQueue() const override;
        bool isEmpty() const override;

    private:
};
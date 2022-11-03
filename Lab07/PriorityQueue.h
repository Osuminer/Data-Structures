#include <string>

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
        void Swap(int&, int&);

        int GetParent(int);
        int GetLeft(int);
        int GetRight(int);

        void BubbleUp(int);
        void BubbleDown(int);

    private:
        int m_heap[SIZE];
        int m_size = 0;
};
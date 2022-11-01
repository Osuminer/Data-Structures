

class PriorityQueue {
    public:
        virtual void Insert() const = 0;  
        virtual void DeQueue() const = 0;
        virtual void PrintPriorityQueue() const = 0;
        virtual bool isEmpty() const = 0;

    private:

};

class ArrayBasedPriorityQueue : PriorityQueue {
    public:
        ArrayBasedPriorityQueue(void);
        virtual ~ArrayBasedPriorityQueue();
        void Insert() const override;
        void DeQueue() const override;
        void PrintPriorityQueue() const override;
        bool isEmpty() const override;

    private:

};

class HeapBasedPriorityQueue : PriorityQueue{
     public:
        HeapBasedPriorityQueue(void);
        virtual ~HeapBasedPriorityQueue();
        void Insert() const override;
        void DeQueue() const override;
        void PrintPriorityQueue() const override;
        bool isEmpty() const override;

    private:
};
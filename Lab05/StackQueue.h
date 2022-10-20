#include <string>



template<typename T> class IStack {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	/// Adds a value to the Stack.  Returns true if able to add, otherwise false
	virtual bool push(const T & val) = 0;
	/// removes a value from the stack.   Feturns true if able to remove an element, otherwise false
	virtual bool pop() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns top of stack
	virtual T peek() const = 0;
	// outputs contents to a string
	virtual std::string toString() const = 0;
	
private:

};



template<typename T> class ArrayBasedStack : IStack {
public:
	ArrayBasedStack(void);
	virtual ~ArrayBasedStack();
	bool isEmpty() const override;
	bool push(const T & val) override;
	bool pop() override;
	//If the ADT is empty throw an exception indicating this
	T peek() const override;
	std::string toString() const override;
private:
	T stack[4];
};


template<typename T> class IQueue {
public:
	///Returns true if empty, otherwise false
	virtual bool isEmpty() const = 0;
	// Adds a value to the Q.  Returns true if able otherwise false
	virtual bool enQueue(const T &val) = 0;
	// remove a value to the Q.  Returns true if able otherwise false
	virtual bool deQueue() = 0;
	//If the ADT is empty throw an exception indicating this, otherwise returns the value of the 
	// front of the Q
	virtual T peekFront() const = 0;

	// outputs contents to a string
	virtual std::string toString() const = 0;
private:

};



template<typename T> class  ArrayBasedQueue : IQueue {
public:
	ArrayBasedQueue(void);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const override;
	bool enQueue(const T &val) override;
	bool deQueue() override;
	//If the ADT is empty throw an exception indicating this
	T peekFront() const override;
	std::string toString() const override;
protected:
	T queue[7];
	int head;
	int tail;

};











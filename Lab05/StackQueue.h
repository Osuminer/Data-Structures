#include <string>

template<typename T> class ArrayBasedStack {
	public:
		ArrayBasedStack(void) {
			top = -1;
		}

		~ArrayBasedStack() {
			top = -1;
		}

		bool isEmpty() const {
				if (top == -1) {
					return true;
				}

			return false;
		}

		bool push(const T & val) {
			if (top == 4) {
				return false;
			}

			top++;
			stack[top] = val;

			return true;
		}

		bool pop() {
			if (top <= 0) {
				return false;
			}

			top--;

			return true;
		}

		T peek() const {
			if (this->isEmpty()) {
				throw "ADT is emtpy";
			} else {
				return stack[top];
			}
		}

		std::string toString() const {
			std::string finalText = "";

			for (int i = 0; i < 4; i++) {
				if (stack[i] != 0) {
					finalText.append(std::to_string(stack[i]));
					finalText.append(" ");
				}
			}

			return finalText;
		}

	private:
		int top;
		T stack[4];

};


template<typename T> class  ArrayBasedQueue {
	public:
		ArrayBasedQueue(void) {
			head = 0;
			tail = 0;
		}

		~ArrayBasedQueue() {
			head = 0;
			tail = 0;
		}

		bool isEmpty() const {
				if(head == tail) {
					return true;
				}
			return false;
		}

		bool enQueue(const T &val) {
			if( this-> isEmpty() ){                               
				queue[head] = val;
				tail++;
				return true;
			} else {
				T hold = this->peekFront();
				queue[tail] = val;
				tail++;
				return true;
			}

			return false;
		}

		bool deQueue() {
			if(this->isEmpty()){                               
				return false;                                     
			} else {                                                                              
				head++;
				return true;
			}
		}

		T peekFront() const {
			if (this->isEmpty()){
				throw "ADT is emtpy";
			} else {
				return queue[head];
			}
		}

		std::string toString() const {
			std::string finalString = "";

			for(int i = 0; i < 7; i++) {
				finalString.append(queue[i] + "\n");
			}

			return finalString;
		}

	protected:
		T queue[7];
		int head;
		int tail;

};


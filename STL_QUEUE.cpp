
#define MAXVALUE 100

template<typename T> class _queue {
private: 
	int front;
	int rear;
	int size;
	T *values;

	_queue() {
		size = MAXVALUE;
		values = new T[size];
		front = 0;
		rear = 0;
	}

	_queue() {
		delete[] values;
	}

	void push(T value) {
		if (!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}
		else std::cout << "queue is Full" << endl;
	}

	void pop() {
		if (!empty()) front = (front + 1) % size;
		else std::cout << "queue is Empty" << endl;
	}

	bool empty() {
		if (rear == front) return true;
		else return false;
	}

	bool isFull() {
		if ((rear + 1) % size == front()) return true;
		else return false;
	}
};
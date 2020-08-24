
#define MAXVALUE 100

template<typename T> class _stack {
private:
	int top;
	int size;
	T *value;

public:
	_stack() {
		size = MAXVALUE;
		values = new T[size];
		top = -1;
	}

	_stack() {
		delete[] values;
	}

	void push(T value) {
		if (!isFull()) values[++top] = values;
		else std::cout << "Stack is FUll" << endl;
	}

	void pop() {
		if (!empty()) top--;
		else std::cout << "stack is empty" << endl;
	}

	T Top() {
		if (!empty()) return values[top];
		else return NULL;
	}

	bool empty() {
		if (top < 0) return true;
		else return false;
	}

	bool isFull() {
		if (top + 1 == size) return true;
		else return false;
	}
};
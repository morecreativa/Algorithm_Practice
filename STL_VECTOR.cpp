/*
This _vector class doesn't supply iterator.

Just use dynamic arrays.
*/

template <typename T> class _vector {
private:
	int capacity = 0;
	int size = 0;
	T *vc;

public:
	_vector(int size = 1) {
		capacity = size;
		vc = new T[size];
	}

	_vector() {
		delete[] vc;
	}

	int size() { return size; }
	bool empty() { return !size; }

	void resize(int size) {
		capacity = size;
		T *tvc = new T[size];
		for (int i = 0; i < size; i++) tcv[i] = vc[i];
		delete[] vc;

		vc = tvc;
	}

	void clear() {
		delete[] vc;
		capacity = 1;
		size = 0;

		vc = new T[1];
	}

	void push_back(T val) {
		if (size == capacity) {
			capacity *= 2;
			resize(capacity);
		}

		vc[size++] = val;
	}

	void pop_back() {
		if (size == 0) return;

		vc[--size] = 0;
	}

	void reverse() {
		for (int i = 0; i < size / 2; i++) {
			T tmp = vc[i];
			vc[i] = vc[(size - 1) - i];
			vc[(size - 1) - i] = tmp;
		}
	}

	T &operator[](const int &i) const { return vc[i]; }
	void operator=(const _vector<T> &tvc) {
		capacity = tvc.capacity;
		size = tvc.size;
		delete[] vc;
		vc = new T[capacity];
		for (int i = 0; i < size; i++) vc[i] = tvc[i];
	}
};
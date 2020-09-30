#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321
#define ll long long

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b; if (a%b == 0) { cout << 0 << endl; continue; }
		int answer = (a / b + 1)*b - a;
		if (answer < 0) answer *= -1;
		cout << answer << endl;
	}
	return 0;
}

#endif // 1

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string str(n, 'a');
		for (int i = 1; k >= 0; i++) {
			k -= i;
			if (k <= 0) {
				str[n - 1 - i] = 'b';
				str[n - i - k] = 'b';
				cout << str << endl;
				break;
			}
		}
	}
	return 0;
}
#endif // 1

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int n;
		string str;
		cin >> n;
		cin >> str;
		vector<int> a(n), b(n);
		bool flag = true;
		for (int i = 0; i < n; i++) {
			int temp = str[i]-48;
			if (temp == 0) {
				a[i] = 0, b[i] = 0;
			}
			else if (temp == 1) {
				if (!flag) a[i] = 0, b[i] = 1;
				else {
					a[i] = 1, b[i] = 0;
					flag = false;
				}
			}
			else {
				if (!flag) b[i] = 2;
				else a[i] = 1, b[i] = 1;
			}
		}
		for (int i = 0; i < n; i++) cout << a[i];
		cout << endl;
		for (int i = 0; i < n; i++) cout << b[i];
		cout << endl;
	}
	return 0;
}

#endif // 1

#if 1

bool same(int a,int b,int c) {
	return (a != b && a != c && b != c);
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n); for (auto &it : arr) cin >> it;
		int ok = 1;
		for (int i = 0; i < arr.size() - 1; i++) if (arr[i] != arr[i + 1]) {
			ok = 0;
			break;
		}
		//if same
		if (ok) {
			cout << 1 << endl;
			for (int i = 0; i < arr.size(); i++) cout << 1 << (i < arr.size()-1) ? ' ' : '\n';
		}
		else if (!ok && same(arr[0], arr[n - 1], arr[n - 2])) {
			cout << 3 << endl;
			for (int i = 0; i < arr.size()-1; i++) {
				if (i % 2 == 0) cout << 1 << ' ';
				else cout << 2 << ' ';
			}
			cout << 3 << endl;
		}
		else {
			cout << 2 << endl;
			for (int i = 0; i < arr.size()-1; i++) {
				if (i % 2 == 0) cout << 1 << ' ';
				else cout << 2 << ' ';
			}
			cout << 2 << endl;
		}
	}
	return 0;
}
#endif // 1

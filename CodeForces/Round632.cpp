#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>

#define fi first
#define se second
#define LL long long
#define pi pair<int,int>
#define pb push_back
#define INF 987654321
#define forn(i,n) for(int i=0;i<int(n);i++)

using namespace std;

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int n, m; 
		cin >> n >> m;
		forn(i, n) {
			forn(j, m) {
				if (j % 2 == 0) cout << 'B';
				else cout << 'W';
			}
			cout << endl;
		}
	}
	return 0;
}

#endif // 1

#if 0

bool isitfull(bool check[3]) {
	forn(i, 3) {
		if (!check[i]) return false;
	}
	return true;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		bool check[3] = { false,false,false };
		if (a[0] != b[0]) {
			cout << "NO" << endl;
			continue;
		}
		bool flag = false;
		for (int i = 1; i < n; i++) {
			if (isitfull(check)) break;
			if (a[i - 1] == 0) check[0] = true;
			else if (a[i - 1] == 1) check[1] = true;
			else check[2] = true;
			if ((b[i] - a[i] < 0 && !check[2]) || (b[i] - a[i] > 0 && !check[1])) {
				flag = true;
				break;
			}
		}
		if (!flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

#endif // 1

#if 1

int main() {
	int n;
	cin >> n;
	vector<LL> prefix(n + 1, 0);
	LL answer = 0;
	forn(i, n) {
		int x; cin >> x;
		if (x != 0) ++answer;
		prefix[i + 1] = prefix[i] + x;
	}
	for (int i = 0; i < n; i++) {
		int pos = i + 1;
		while (pos <= n && !(prefix[pos] - prefix[i] == 0)) {
			++pos;
		}
		if (pos - i - 2 > 0) answer += pos - i - 2;
	}
	cout << answer;
	return 0;
}

#endif // 1

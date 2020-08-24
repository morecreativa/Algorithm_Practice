#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

#define INF 987654321
#define LL long long

#if 0

#define BOUND 200000000
bool in(LL x, LL y, LL x1, LL y1, LL x2, LL y2) {
	return (-BOUND <= x1 && x1 <= x && x <= x2 && x2 <= BOUND
		&& -BOUND <= y1 && y1 <= y && y <= y2 && y2 <= BOUND);
}

int main() {
	int T; cin >> T;
	while (T--) {
		string answer = "YES";
		vector<LL> hm(4);
		for (auto &it : hm) cin >> it;
		LL x, y; cin >> x >> y;
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		if ((x2 - x1 == 0) && (hm[0] || hm[1])) answer = "NO";
		if ((y2 - y1 == 0) && (hm[2] || hm[3])) answer = "NO";
		if (!in(x - hm[0] + hm[1], y - hm[2] + hm[3], x1, y1, x2, y2)) answer = "NO";
		cout << answer << endl;
	}
	return 0;
}

#endif // 1

#if 0

bool in(int a, int b) {
	for (int i = 2; a / i != 0 && b / i != 0; i++) {
		if (a%i == 0 && b%i == 0) return true;
	}
	return false;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int m = 1;
		vector<int>arr(n); for (auto &it : arr) cin >> it;
		vector<int>answer(n, -1);
		answer[0] = m;
		for (int i = 0; i < n; i++) {
			if (answer[i] == -1) {
				++m;
				answer[i] = m;
			}
			for (int j = i + 1; j <n; j++)
				if (in(arr[j], arr[i])) answer[j] = answer[i];
		}
		cout << m << endl;
		for (int i = 0; i < n; i++) cout << answer[i] << ' ';
		cout << endl;
	}
	return 0;
}
#endif // 1

#if 1

int main() {
	int T; cin >> T;
	while (T--) {
		LL answer = 0;
		int n, k; cin >> n >> k;
		vector<vector<int>> v(k, vector<int>(26, 0));
		string str = "";
		cin >> str;
		for(int i=0;i<k;i++)
			for (int j = 0; j < n / k; j++) {
				++v[i][str[j*k + i] - 97];
			}
		for (int i = 0; i < k / 2; i++) {
			vector<int> arr(26);
			for (int j = 0; j < arr.size(); j++) arr[j] = v[i][j] + v[k - i - 1][j];
			int max_num = 0;
			for (int j = 0; j < arr.size(); j++) max_num = max(max_num, arr[j]);
			answer += (n / k * 2 - max_num);
		}
		if (k % 2) {
			int max_num = 0;
			for (int j = 0; j < v[k / 2].size(); j++) max_num = max(max_num, v[k / 2][j]);
			answer += (n / k - max_num);
		}
		cout << answer << endl;
	}
	return 0;
}

#endif // 1

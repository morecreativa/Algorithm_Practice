#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

#define INF 987654321
#define ll long long

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		ll x; cin >> x;
		ll y = x - 1;
		cout << 1 << ' ' << y << endl;
	}
	return 0;
}

#endif // 1

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int n; 	cin >> n;
		int answer = n;
		vector<int> arr(n);
		for (auto &it : arr) cin >> it;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() - 1; i++) {
			if (arr[i] == arr[i + 1]) answer--;
		}
		cout << answer << endl;
	}
	return 0;
}

#endif // 1

#if 1

int main() {
	int n; cin >> n;
	int ans[1005];
	vector<int> v[1005];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(i);
		v[b].push_back(i);
		ans[i] = -1;
	}
	pair<int, int> mx(0, 0);
	for (int i = 1; i <= n; i++)
		mx = max(mx, make_pair((int)v[i].size(), i));
	int cur = 0;
	for (int i : v[mx.second]) 
		ans[i] = cur++;
	for (int i = 1; i < n; i++) {
		if (ans[i] == -1) ans[i] = cur++;
		cout << ans[i] << endl;
	}
}
#endif // 1

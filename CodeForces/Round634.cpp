#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_set>

#define INF 987654321
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define LL long long
#define fi first
#define se second
#define sz(a) int((a).size())
#define forn(i,n) for(int i=0;i<n;i++)


using namespace std;

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		LL n;
		cin >> n;
		cout << (n % 2 ? n / 2 : n / 2 - 1) << endl;
	}
	return 0;
}

#endif // 1

#if 0
int main() {
	int T; cin >> T;
	while (T--) {
		int n, a, b;
		cin >> n >> a >> b;
		string str = "";
		string answer = "";
		for (int i = 0; i < b; i++) str += 'a' + i;
		for (int i = 0; i < n / b; i++) answer.append(str);
		str = str.substr(0, n%b);
		answer.append(str);
		cout << answer << endl;
	}
	return 0;
}
#endif // 1

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int cnt[200010] = { 0, };
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < arr.size(); i++) {
			int x = 0; cin >> x;
			arr[i] = x;
			cnt[x]++;
		}
		unordered_set<int> arrset;
		for (auto x : arr) arrset.insert(x);
		int a = arrset.size();
		int b = 0;
		for (int i = 0; i <= n; i++) b = max(b, cnt[i]);
		int c = n / 2;
		int answer = (a > b ? b : a);
		if (a == b) answer = b - 1;
		if (answer > c) cout << c << endl;
		else cout << answer << endl;
	}
	return 0;
}

#endif // 1

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		int map[9][9];
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) scanf("%1d", &map[i][j]);
		int cx = 0, cy = 0;
		for (int i = 0; i < 9; i++) {
			if (map[cx][cy] == 9) map[cx++][cy] = 1;
			else map[cx++][cy]++;
			cy = cx / 3 + 3 * (cx % 3);
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
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
		int ans = 0;
		cin >> n;
		vector<int> a(n); for (auto &x : a) cin >> x;
		vector<vector<int>> cnt(200, vector<int>(n + 1));
		vector<vector<int>> pos(200);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 200; j++) cnt[j][i + 1] = cnt[j][i];
			++cnt[a[i] - 1][i + 1];
			pos[a[i] - 1].pb(i);
		}
		for (int i = 0; i < 200; i++) {
			ans = max(ans, sz(pos[i]));
			for (int p = 0; p < pos[i].size()/2; ++p) {
				int l = pos[i][p] + 1, r = pos[i][sz(pos[i]) - 1 - p] - 1;
				for (int el = 0; el < 200; ++el) {
					int sum = cnt[el][r + 1] - cnt[el][l];
					ans = max(ans, sum + 2 * (p + 1));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

#endif // 1

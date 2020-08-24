#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define le left
#define ri right
#define INF 987654321
#define ll long long
#define pb push_back

#if 0

int main() {
	int T; cin >> T;
	while (T--) {
		ll n, k; cin >> n >> k;
		if (n < k*k) {
			cout << "NO" << endl;
			continue;
		}
		int temp = n - k * k;
		if (temp % 2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

#endif // 1

#if 1

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<vector<int>> arr(n + 1);
		pair<int, int> answer = { INF,INF };
		bool visit[100005] = { 0, };
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			for (int j = 0; j < x; j++) {
				int temp = 0;
				cin >> temp; arr[i + 1].pb(temp);
			}
		}
		for (int i = 1; i < arr.size(); i++) {
			bool flag = true;
			for (int j = 0; j < arr[i].size(); j++) {
				if (visit[arr[i][j]]) continue;
				else {
					visit[arr[i][j]] = true;
					flag = false;
					break;
				}
			}
			if (flag) answer.first = i;
		}
		for (int i = 1; i <=n; i++) {
			if (!visit[i]) answer.second = i;
		}
		if (answer.first == INF) { cout << "OPTIMAL" << endl; }
		else {
			cout << "IMPROVE" << endl;
			cout << answer.first << ' ' << answer.second << endl;
		}
	}
	return 0;
}

#endif // 1

#if 0

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

string strpush(string ret,int ud,int lr) {
	if (ud > 0)	for (int i = 0; i < ud; i++) ret.append("D");
	else for (int i = 0; i < -ud; i++) ret.append("U");

	if (lr > 0) for (int i = 0; i < lr; i++) ret.append("R");
	else for (int i = 0; i < lr; i++) ret.append("L");
	return ret;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> cur_(k);
	vector<pair<int, int>> fin_(k);
	vector<pair<int,int>> dist(k);
	for (int i = 0; i < k; i++) {
		int cx, cy;
		cin >> cx >> cy; cur_.pb({ cx,cy });
	}
	for (int i = 0; i < k; i++) {
		int cx, cy;
		cin >> cx >> cy; fin_.pb({ cx,cy });
		dist[i].second = i;
		dist[i].first = abs(cur_[i].first - fin_[i].first) + abs(cur_[i].second - cur_[i].second);
	}
	sort(dist.begin(), dist.end());
	queue<int> q; for (int i = 0; i < k; i++) q.push(dist[i].second);
	string answer = "";
	for (int i = 0; i < 2 * m*n; i++) {
		int idx_cur = q.front(); q.pop();
		int upordown = fin_[idx_cur].first - cur_[idx_cur].first;
		int leftorright = fin_[idx_cur].second - cur_[idx_cur].second;
		for (int j = 0; j < n; i++) {
			cur_[i].first += upordown;
			cur_[i].second += leftorright;
		}
		answer = strpush(answer, upordown, leftorright);
	}
	return 0;
}

#endif // 1

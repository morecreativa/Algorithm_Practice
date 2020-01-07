#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 98765

int answer = 0;
int n, m, c;
int map[10][10];
int visit[10][10];

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int>arr) {
	int score = 0;
	sort(arr.begin(), arr.end(), desc);
	FOR(idx, m ) {
		int sub_sum = 0;
		int sum = 0;
		queue<int>q;
		for (int i = idx; i < m; i++){
			if (sub_sum + arr[i] > c) continue;
			q.push(arr[i]);
			sub_sum += arr[i];
		}
		while (!q.empty()){
			int cur = q.front();
			sum += cur * cur;
			q.pop();
		}
		score = max(score, sum);
	}
	return score;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> n >> m >> c;
		FOR(i, n) FOR(j, n) cin >> map[i][j];

		// Start searching
		pair<pair<int, int>, int> p;
		FOR(l, 2) {
			p.second = 0;
			FOR(i, n) for (int j = 0; j <= n - m; j++) {
				vector<int> arr(m);
				bool flag = false;
				FOR(k, m) {
					if (visit[i][j + k]) {flag = true; break;}
					arr[k] = map[i][j + k];
				}
				if (flag)	continue;

				int score = solution(arr);
				if (score > p.second) {
					p.first.first = i;
					p.first.second = j;
					p.second = score;
				}
			}
			FOR(k, m) visit[p.first.first][p.first.second + k] = l + 1;
			answer += p.second;
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 98765

int answer = INF;
int N;
int map[16][16];
bool visit[16];

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = i; j < N; j++) {
				if (visit[i] && visit[j])
					sum1 += (map[i][j] + map[j][i]);
				else if (!visit[i] && !visit[j])
					sum2 += (map[i][j] + map[j][i]);
			}
		answer = min(answer, abs(sum1 - sum2));
		return;
	}
	if (idx == N - 1) return;
	for (int i = idx; i <= N - 1; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	int T, test_case;
	char a = 'c';
	double b;
	float f;
	long long tt;
	string str = "Hello world";

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> N;
		FOR(i, N)FOR(j, N) cin >> map[i][j];
		FOR(i, N - 3) {
			visit[i] = true;
			dfs(i, 1);
			visit[i] = false;
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = INF;
	}
	return 0;
}
#endif // 0
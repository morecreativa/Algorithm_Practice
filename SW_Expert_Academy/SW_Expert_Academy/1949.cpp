#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 987654321

int answer = 0;
int n, k;
int m[8][8];
bool check[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int cx, int cy, int dist, int flag) {
	FOR(i, 4) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx<0 || ny<0 || nx>(n - 1) || ny>(n - 1))continue;
		if (!check[nx][ny] && m[nx][ny] < m[cx][cy]) {
			check[nx][ny] = true;
			dfs(nx, ny, dist + 1, flag);
			check[nx][ny] = false;
		}
		else {
			if (!flag) {
				for (int j = 1; j <= k; j++)
					if (!check[nx][ny] && m[nx][ny] - j < m[cx][cy]) {
						m[nx][ny] -= j;
						check[nx][ny] = true;
						dfs(nx, ny, dist + 1, true);
						m[nx][ny] += j;
						check[nx][ny] = false;
					}
			}
		}
	}
	answer = max(answer, dist);
	return;
}

int main()
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int max_height = 0;
		cin >> n >> k;
		answer = 0;
		memset(m, -10, sizeof(m));
		memset(check, false, sizeof(check));
		FOR(i, n)
			FOR(j, n) {
			cin >> m[i][j];
			max_height = max(max_height, m[i][j]);
		}

		FOR(i, n)
			FOR(j, n) {
			if (m[i][j] == max_height) {
				check[i][j] = true;
				dfs(i, j, 1, false);
				check[i][j] = false;
			}
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define INF 987654321

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int turnnel[50][50];
bool visit[50][50];
bool dfs_visit[50][50];
int turnnel_type[8][4] = {
	{0,0,0,0},
	{1,1,1,1},
	{1,1,0,0},
	{0,0,1,1},
	{1,0,0,1},
	{0,1,0,1},
	{0,1,1,0},
	{1,0,1,0}
};
int n, m;
int r, c;
int L;
int Answer = 0;

bool check(int cur, int nx, int direction) {
	if (!turnnel_type[cur][direction]) return 0;

	if (direction == 0) direction = 1;
	else if (direction == 1)direction = 0;
	else if (direction == 2)direction = 3;
	else if (direction == 3)direction = 2;

	if (!turnnel_type[nx][direction]) return 0;
	return 1;
}

void dfs(int cx, int cy, int time) {
	if (time > L) return;

	visit[cx][cy] = true;
	FOR(i, 4) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx<0 || ny<0 || nx>(n - 1) || ny>(m - 1)) continue;
		if (!dfs_visit[nx][ny] && check(turnnel[cx][cy], turnnel[nx][ny], i)) {
			dfs_visit[nx][ny] = true;
			dfs(nx, ny, time + 1);
			dfs_visit[nx][ny] = false;
		}
	}
	return;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(turnnel, INF, sizeof(turnnel));
		cin >> n >> m >> r >> c >> L;
		FOR(i, n)
			FOR(j, m) cin >> turnnel[i][j];
		//Start DFS
		dfs_visit[r][c] = true;
		dfs(r, c, 1);
		FOR(i, n)
			FOR(j, m) if (visit[i][j]) Answer++;
		cout << '#' << test_case + 1 << ' ' << Answer << endl;
		//test_case의 초기화
		Answer = 0;
		memset(visit, false, sizeof(visit));
		memset(dfs_visit, false, sizeof(dfs_visit));
	}
	return 0;
}
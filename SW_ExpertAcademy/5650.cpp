#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define PAIR pair<pair<int,int>,int>
#define INF 98765

int answer = 0;
int n;
int map[100][100];
bool warm_chk[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int change[6][4] = {
{0,0,0,0},
{1,3,0,2},
{3,0,1,2},
{2,0,3,1},
{1,2,3,0},
{1,0,3,2}
};

PAIR cnt(PAIR p) {
	p.first.first += dx[p.second];
	p.first.second += dy[p.second];
	return p;
}

void solution(PAIR p, int score,int cx,int cy) {
	while (true) {
		int	nx = p.first.first;
		int ny = p.first.second;

		//Wall
		if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) {
			p.first.first -= dx[p.second]; p.first.second -= dy[p.second];
			p.second = change[5][p.second];
			score++; continue;
		}

		//End Condition
		if ((nx == cx && ny == cy) || map[nx][ny] == -1) {
			answer = max(answer, score);
			return;
		}

		//None Blocked
		if (map[nx][ny] == 0) {
			cnt(p);
			continue;
		}

		//Blocked 
		if (map[nx][ny] > 0 && map[nx][ny] <= 5) {
			p.second = change[map[nx][ny]][p.second];
			cnt(p);
			score++;
			continue;
		}
		//Hole
		if (map[nx][ny] >= 6 && map[nx][ny] <= 10) {
			warm_chk[nx][ny] = true;
			bool warm = false;
			FOR(i, n) {
				FOR(j, n)
					if (!warm_chk[i][j] && map[i][j] == map[nx][ny]) {
						warm_chk[nx][ny] = false;
						p.first.first = i + dx[p.second];
						p.first.second = j + dy[p.second];
						warm = true; break;
					}
				if (warm) break;
			}
		}
		//finished
	}
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(map, INF, sizeof(map));
		cin >> n;
		FOR(i, n) FOR(j, n) cin >> map[i][j];
		PAIR p;
		//start
		FOR(i, n)FOR(j, n) if (map[i][j] == 0) {
			FOR(k, 4) {
				p.first.first = i + dx[k];
				p.first.second = j + dy[k];
				p.second = k;
				solution(p, 0, i, j);
			}
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
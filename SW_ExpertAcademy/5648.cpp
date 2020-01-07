#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_N 4001
#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define INF 98765

int N;
int answer = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[MAX_N][MAX_N];

typedef struct {
	int px, py, dir, k;
}atom;

bool range_check(int nx, int ny) {
	if (nx<0 || nx>MAX_N || ny<0 || ny>MAX_N) return false;
	return true;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(map, 0, sizeof(map));
		queue<atom> q;
		cin >> N;
		FOR(i, N) {
			int x, y, direction, kinetic;
			cin >> x >> y >> direction >> kinetic;
			q.push({ 2 * y + 2000,2 * x + 2000,direction,kinetic });
			map[2 * y + 2000][2 * x + 2000] = kinetic;
		}
		while (!q.empty())
		{
			atom cur_atom = q.front();
			q.pop();
			if (map[cur_atom.px][cur_atom.py] > cur_atom.k) {
				answer += map[cur_atom.px][cur_atom.py];
				map[cur_atom.px][cur_atom.py] = 0;
				continue;
			}
			else if (map[cur_atom.px][cur_atom.py] == 0) continue;

			map[cur_atom.px][cur_atom.py] = 0;

			atom nxt_atom = cur_atom;
			nxt_atom.px = cur_atom.px + dx[cur_atom.dir];
			nxt_atom.py = cur_atom.py + dy[cur_atom.dir];
			3 2
			if (range_check(nxt_atom.px, nxt_atom.py)) {
				if (map[nxt_atom.px][nxt_atom.py] != 0) {
					map[nxt_atom.px][nxt_atom.py] += nxt_atom.k;
				}
				else{
					map[nxt_atom.px][nxt_atom.py] = nxt_atom.k;
					q.push(nxt_atom);
				}
			}
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
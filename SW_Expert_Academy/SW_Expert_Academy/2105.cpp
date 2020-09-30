#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 98765

int answer = 0;
int N;
int map[20][20];
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };

bool RANGE_CHECK(int nx, int ny) {
	if (nx<0 || nx>(N - 1) || ny<0 || ny>(N - 1)) return false;
	else return true;
}

bool VECTOR_CHECK(vector<int>temp) {
	sort(temp.begin(), temp.end());
	FOR(i, temp.size() - 1)
		if (temp[i] == temp[i + 1]) return false;
	return true;
}

void sol(int cx, int cy) {
	//For range with Search len
	for (int i = N - 2; i >= 1; i--)
		for (int j = N - 1 - i; j >= 1; j--) {
			int nx = cx;
			int ny = cy;
			vector<int>food;
			food.push_back(map[nx][ny]);
			bool flag = false;
			FOR(k, 4) {
				int n;
				if (k % 2 == 0) n = i;
				else n = j;
				FOR(l, n) {
					nx += dx[k];
					ny += dy[k];
					if (!RANGE_CHECK(nx, ny)) { flag = true; break; }
					if (nx == cx && ny == cy) break;
					food.push_back(map[nx][ny]);
				}
				if (flag)break;
			}
			if (VECTOR_CHECK(food) && !flag)
				answer = max(answer, (int)food.size());
		}
	return;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(map, 0, sizeof(map));
		cin >> N;
		FOR(i, N)FOR(j, N) cin >> map[i][j];
		FOR(i, N - 2)for (int j = 1; j <= N - 2; j++) {
			sol(i, j);
		}
		if (answer == 0) answer = -1;
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
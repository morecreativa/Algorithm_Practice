#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 987654321
#define pp pair<int,pair<int,pair<int,int>>>
// pair 세로위치, 가로위치, 미생물 수, 이동방향

int n, k;
// k= 군집의 개수
int m; // 격리시간 
int Answer = 0;
int pos[100][100];
int collapsed[100][100];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0 ,0,0,-1,1 };

int switch_direction(int dir) {
	if (dir == 1) dir = 2;
	else if (dir == 2) dir = 1;
	else if (dir == 3) dir = 4;
	else if (dir == 4) dir = 3;
	return dir;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		vector<pp> insects;
		memset(pos, 0, sizeof(pos));
		memset(collapsed, 0, sizeof(collapsed));
		cin >> n >> m >> k;

		FOR(i, n)
			FOR(j, n) {
			if (i == 0 || i == (n - 1) || j == 0 || j == (n - 1)) pos[i][j] = INF;
		}

		FOR(i, k) {
			int pos_x, pos_y, insects_num, direction;
			cin >> pos_x >> pos_y >> insects_num >> direction;
			insects.push_back(make_pair(pos_x, make_pair(pos_y, make_pair(insects_num, direction))));
		}

		// Move for Time
		FOR(i, m)
		{
			//move
			queue<pp> Q;
			FOR(j, insects.size()) Q.push(insects[j]);

			int cnt = 0;
			pp cur;
			while (!Q.empty())
			{
				cur = Q.front();
				Q.pop();
				int dir = cur.second.second.second;
				FOR(j, 5) {
					if (dir == j) {
						cur.first += dx[dir];
						cur.second.first += dy[dir];
						if (pos[cur.first][cur.second.first] == INF) {
							cur.second.second.second = switch_direction(dir);
							cur.second.second.first /= 2;
						}
					}
				}
				insects[cnt] = cur; cnt++;
				collapsed[cur.first][cur.second.first]++;
			}

			// Collapsed_check
			FOR(p, n)
				FOR(q, n) {
				if (collapsed[p][q] > 1)
				{
					vector<int> idx;
					int sum = 0;
					int temp_number = 0;
					int dir = 0;
					FOR(e, insects.size())
					{
						if (insects[e].first == p && insects[e].second.first == q)
						{
							int temp = insects[e].second.second.first;
							sum += insects[e].second.second.first;
							if (temp_number < temp) { dir = insects[e].second.second.second; temp_number = temp; }
							//insects.erase(insects.begin() + e);
							idx.push_back(e);
						}
					}
					FOR(u, idx.size())
						insects.erase(insects.begin() + idx[u] - u);
					insects.push_back(make_pair(p, make_pair(q, make_pair(sum, dir))));
				}
			}
			memset(collapsed, 0, sizeof(collapsed));
		}

		FOR(i, insects.size()) {
			Answer += insects[i].second.second.first;
		}
		cout << '#' << test_case + 1 << ' ' << Answer << endl;
		Answer = 0;
	}
	return 0;
}
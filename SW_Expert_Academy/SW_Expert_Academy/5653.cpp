#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define INF 9876
#define MAX_N 651

int answer = 0;
int N, M, K;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int STAT[MAX_N][MAX_N];
int ORIG[MAX_N][MAX_N];
int MAP[MAX_N][MAX_N];

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		memset(MAP, 0, sizeof(MAP));
		memset(STAT, 0, sizeof(STAT));
		memset(ORIG, 0, sizeof(ORIG));
		cin >> N >> M >> K;
		FOR(i, N)FOR(j, M) {
			cin >> MAP[i + 300][j + 300];
			ORIG[i + 300][j + 300] = MAP[i + 300][j + 300];
			if (MAP[i + 300][j + 300] != 0)STAT[i + 300][j + 300] = 1;
		}
		for (int i = 1; i <= K; i++) {
			//breeding
			for (int x = 300 - i; x < 300 + i + N; x++)
				for (int y = 300 - i; y < 300 + i + M; y++) {
					if (MAP[x][y] == 0) continue;

					if (STAT[x][y] == 2) {
						FOR(dir, 4) {
							int nx = x + dx[dir];
							int ny = y + dy[dir];
							if (MAP[nx][ny] != 0 && STAT[nx][ny] == 5) {
								//compare with New Breed
								MAP[nx][ny] = max(MAP[nx][ny], ORIG[x][y]);
								ORIG[nx][ny] = MAP[nx][ny];
							}
							else if (MAP[nx][ny] == 0 && STAT[nx][ny] == 0) {
								MAP[nx][ny] = ORIG[x][y];
								ORIG[nx][ny] = MAP[nx][ny];
								STAT[nx][ny] = 5;
							}
						}
						STAT[x][y] = 3;
					}
				}

			//check origin & status
			for (int x = 300 - i; x < 300 + i + N; x++)
				for (int y = 300 - i; y < 350 + i + M; y++) {
					if (MAP[x][y] == 0) continue;
					if (STAT[x][y] == 5) { STAT[x][y] = 1; continue; }

					MAP[x][y]--;
					if (MAP[x][y] == 0) {
						if (STAT[x][y] == 1) {
							STAT[x][y] = 2;
							MAP[x][y] = ORIG[x][y];
						}
						else if (STAT[x][y] == 3) STAT[x][y] = 4;
					}
				}
			//Finished
		}

		//answer
		for (int x = 300 - K; x < 350 + K; x++)
			for (int y = 300 - K; y < 350 + K; y++) {
				if (STAT[x][y] >= 1 && STAT[x][y] <= 3) answer++;
			}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}

//cout << i << endl;
//for (int x = 280; x < 320; x++) {
//	for (int y = 280; y < 320; y++) {
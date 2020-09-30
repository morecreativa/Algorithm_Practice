#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long 
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 98765

int answer = 0;
int map[20][20];
int N, X;

bool vector_check(vector<pair<int, int>>arr) {
	for (int j = 0; j < N - 1; j++) {
		if (arr[j].first != arr[j + 1].first) {
			//Left
			if (arr[j].first > arr[j + 1].first&&arr[j + 1].second != 1) return false;
			//Right
			else if (arr[j].first < arr[j + 1].first&&arr[j].second != 1) return false;
		}
		else if (arr[j].second >= 2) return false;
	}
	return true;
}

bool solutin_func(vector<pair<int, int>>arr) {
	//Search Tri
	for (int i = 0; i < N - 1; i++) {
		if (arr[i].first != arr[i + 1].first) {
			//Left
			if (arr[i].first + 1 == arr[i + 1].first&&i >= X - 1) {
				bool flag = false;
				for (int j = i; j > i - X + 1; j--) {
					if (arr[j].first != arr[j - 1].first) { flag = true; break; }
				}
				if (!flag) for (int j = i; j >= i - X + 1; j--) arr[j].second++;
			}
			//Right
			if (arr[i].first == arr[i + 1].first + 1 && i < N - X) {
				bool flag = false;
				for (int j = i + 1; j < i + X; j++) {
					if (arr[j].first != arr[j + 1].first) { flag = true; break; }
				}
				if (!flag)for (int j = i + 1; j <= i + X; j++)arr[j].second++;
			}
		}
	}

	if (!vector_check(arr)) return false;
	return true;
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		cin >> N >> X;
		FOR(i, N)FOR(j, N) cin >> map[i][j];

		//sol start
		FOR(i, N) {
			vector<pair<int, int>> vp(N);
			FOR(j, N) { vp[j].first = map[i][j]; vp[j].second = 0; }
			if (solutin_func(vp)) answer++;
		}
		FOR(i, N) {
			vector<pair<int, int>> vp(N);
			FOR(j, N) { vp[j].first = map[j][i]; vp[j].second = 0; }
			if (solutin_func(vp)) answer++;
		}
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
#endif // 0

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 98765

int answer = 0;
int MAG[4][8];
int score[4] = { 1,2,4,8 };
int k;

void move(int idx, int dir) {
	int temp = 0;
	if (dir == 1) {
		temp = MAG[idx][7];
		for (int i = 6; i >= 0; i--) {
			MAG[idx][i + 1] = MAG[idx][i];
			if (i == 0) MAG[idx][i] = temp;
		}
	}
	else {
		temp = MAG[idx][0];
		for (int i = 1; i <= 7; i++) {
			MAG[idx][i - 1] = MAG[idx][i];
			if (i == 7) MAG[idx][i] = temp;
		}
	}
	return;
}

void else_move(int idx, int dir, bool lf, bool rf, bool ff) {
	if (idx != 3 && MAG[idx][2] != MAG[idx + 1][6] && rf) {
		else_move(idx + 1, dir*(-1), false, true, false);
		move(idx + 1, dir*(-1));
	}
	if (idx != 0 && MAG[idx][6] != MAG[idx - 1][2] && lf) {
		else_move(idx - 1, dir*(-1), true, false, false);
		move(idx - 1, dir*(-1));
	}
	if (ff) move(idx, dir);
	return;
}


//10
//
//2
//
//0 0 1 0 0 1 0 0
//
//1 0 0 1 1 1 0 1
//
//0 0 1 0 1 1 0 0
//
//0 0 1 0 1 1 0 1
//
//1 1
//
//3 -1

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		cin >> k;
		vector<pair<int, int>>info(k);
		FOR(i, 4)FOR(j, 8) cin >> MAG[i][j];
		FOR(i, k) { cin >> info[i].first >> info[i].second; }

		FOR(i, k) {
			else_move(info[i].first - 1, info[i].second, true, true, true);
		}
		FOR(i, 4) answer += score[i] * MAG[i][0];
		cout << '#' << test_case + 1 << ' ' << answer << endl;
		answer = 0;
	}
	return 0;
}
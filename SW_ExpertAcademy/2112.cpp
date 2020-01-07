#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long
#define INF 98765

int ans = 0;
int d, w, k;
int check_arr[13];
int arr[13][20];
int temp_arr[13][20];

bool check() {
	FOR(j, w) {
		int temp = 1;
		bool flag = false;
		FOR(i, d-1) {
			if (temp_arr[i][j] == temp_arr[i + 1][j]) temp++;
			else temp = 1;
			if (temp >= k) flag=true;
		}
		if (!flag) return true;
	}
	return false;
}

// int dd for col idx, int temp_ans for num of checked_column
void solve(int dd,int temp_ans) {
	// if error not checked return && col checked
	if (!check()) { ans = min(ans, temp_ans); return; }
	if (temp_ans >= ans || dd >= d) return;

	// 1. not change	2. Change with A	3. Change with B
	solve(dd + 1, temp_ans);

	FOR(j, w)temp_arr[dd][j] = 1; solve(dd + 1, temp_ans + 1);
	FOR(j, w)temp_arr[dd][j] = 0; solve(dd + 1, temp_ans + 1);

	// initialize with original
	FOR(j, w) temp_arr[dd][j] = arr[dd][j];
}

int main()
{
	int T, test_case;
	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		//initiatialize
		ans = INF;
		memset(arr, 0, sizeof(arr));
		memset(check_arr, 0, sizeof(check_arr));
		memset(temp_arr, 0, sizeof(temp_arr));

		//input
		cin >> d >> w >> k;
		FOR(i, d) FOR(j, w) {
			cin >> arr[i][j];
			temp_arr[i][j] = arr[i][j];
		}
		solve(0, 0);
		cout << '#' << test_case + 1 << ' ' << ans << endl;
	}

	return 0;
}
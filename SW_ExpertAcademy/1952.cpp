//부분합
#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 987654321
#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long

int cache[12];
int cal[12];
int pay_fee[4];

int main() {
	int T, test_case;
	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		memset(cache, 0, sizeof(cache));
		FOR(i, 4) cin >> pay_fee[i];
		FOR(i, 12) cin >> cal[i];

		FOR(idx, 12) {
			int sum = cal[idx] * pay_fee[0];
			if (cal[idx] * pay_fee[0] > pay_fee[1]) sum = pay_fee[1];
			if (idx == 0) { cache[idx] = sum; continue; }
			cache[idx] = cache[idx - 1] + sum;
			if (idx >= 2) {
				if (idx == 2 && (cache[idx] > pay_fee[2])) cache[idx] = cache[idx - 3] + pay_fee[2];
				else if (cache[idx] - cache[idx - 3] > pay_fee[2]) cache[idx] = cache[idx - 3] + pay_fee[2];
			}
		}
		// compare with year pay
		if (cache[11] > pay_fee[3]) cache[11] = pay_fee[3];
		cout << '#' << test_case + 1 << ' ' << cache[11] << endl;
	}
	return 0;
}

#endif // 0


// DP <- 좀 어설픈 DP
#if 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 987654321

int cache[12];
int cal[12];
int pay_fee[4];

int solve(int cur) {
	if (cur < 0) return 0;
	if (cache[cur] != -1) return cache[cur];

	cache[cur] = solve(cur - 1) + cal[cur] * pay_fee[0];
	cache[cur] = solve(cur - 1) + min(pay_fee[1], cache[cur] - solve(cur - 1));
	cache[cur] = solve(cur - 3) + min(cache[cur] - solve(cur - 3), pay_fee[2]);

	return cache[cur];
}

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		FOR(i, 4) cin >> pay_fee[i];
		FOR(i, 12) cin >> cal[i];

		memset(cache, -1, sizeof(cache));

		int ans = 0;
		FOR(idx, 12) {
			ans = solve(idx);
		}
		if (ans > pay_fee[3]) ans = pay_fee[3];
		cout << '#' << test_case + 1 << ' ' << ans << endl;
	}
	return 0;
}
#endif // 1
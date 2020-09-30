#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_set>

#define INF 987654321
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define LL long long
#define fi first
#define se second
#define sz(a) int((a).size())
#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

#if 0
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		if (n == 1 || m == 1) cout << "YES" << endl;
		else if (n == 2 && m == 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
#endif // 1

#if 0

int main() {
	int T; cin >> T;
	vector<LL> arr;
	LL sum = 0; 
	arr.pb(sum);
	arr.pb(sum + 2);
	sum += 2;
	for (LL i = 2; sum < 1000000000; ++i) {
		sum = sum + 2 * i + i - 1;
		arr.pb(sum);
	}
	while (T--) {
		LL n; cin >> n;
		int i;
		int ans = 0;
		for (i = 0; i < sz(arr); ++i) {
			if (n < arr[i]) break;
		}
		--i;
		while (i!=0) {
			if (n >= arr[i]) {
				n -= arr[i];
				++ans;
			}
			if (n < arr[i])
				--i;
		}
		cout << ans << endl;
	}
	return 0;
}

#endif // 1

#if 1

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n);
		forn(i, sz(a)) {
			int x; cin >> x;
			a[i] = (i + x) % n; if (a[i] < 0) a[i] *= -1;
		}
		sort(a.begin(), a.end());
		bool flag = true;
		forn(i, sz(a)) 
			if (a[i] != i) {
				flag = false;
				break;
			}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

#endif // 1

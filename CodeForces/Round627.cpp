#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T; cin >> T;

	while (T--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < arr.size(); i++) {
			int temp;
			cin >> temp; arr[i] = temp;
		}
		sort(arr.begin(), arr.end());
		bool flag = true;
		for (int i = 0; i < arr.size() - 1; i++) {
			if ((arr[i + 1] - arr[i]) % 2 != 0) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}
#endif // 0

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> arr(n);
		int cnt[5001] = { 0, };
		int max_num = 0;
		for (int i = 0; i < n; i++) { int temp; cin >> temp; arr[i] = temp; cnt[arr[i]]++; max_num = max(max_num, temp); }
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				cnt[arr[i]]--;
				i++;
			}
		}
		bool flag = true;
		for (int i = 0; i <= max_num; i++) {
			if (cnt[i] >=2) {
				flag = false;
				break;
			}
		}
		if (!flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
#endif // 1

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
#define INF 987654321
int main() {
	int T; cin >> T;
	while (T--) {
		string str; cin >> str;
		str = 'R' + str + 'R';
		int cur_ = 0;
		int answer = 0;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == 'R') {
				answer = max(answer, i - cur_);
				cur_ = i;
			}
		}
		cout << answer << endl;
	}
	return 0;
}
#endif // 1

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define INF 987654321

int main() {
	int n; cin >> n;
	ll answer = 0;
	vector<int> a(n), b(n);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	vector<int> sub_(n);
	for (int i = 0; i < sub_.size(); i++) sub_[i] = a[i] - b[i];
	sort(sub_.begin(), sub_.end());
	for (int i = 0; i < sub_.size(); i++) {
		if (sub_[i] <= 0) continue;
		int pos = lower_bound(sub_.begin(), sub_.end(), -sub_[i] + 1) - sub_.begin();
		answer += i - pos;
	}
	cout << answer;
	return 0;
}
#endif // 1

#if 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool in(int x,int l,int r) {
	return l <= x && x <= r;
}

int main() {
	int n, h, l, r;
	cin >> n >> h >> l >> r;

	vector<int> a(n); for (auto &it : a) cin >> it;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));

	dp[0][0] = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		for (int j = 0; j < i + 1; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + in((sum-j) % h, l, r));
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + in((sum-j-1)%h, l, r));
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
	return 0;
}

#endif // 1

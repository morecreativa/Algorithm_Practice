#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int T, test_case;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		int ans = 0;
		int n, k;
		cin >> n >> k;
		vector<int> dia;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			cin >> temp;
			dia.push_back(temp);
		}
		sort(dia.begin(), dia.end());
		int idx = 0;
		bool flag = true;
		while (1) {
			if (!flag) break;
			// idx가 계속 바뀜
			int cnt = 0;
			for (int i = idx; i < dia.size(); i++) {
				if (dia[i] - dia[idx] <= k) ++cnt;
				else {
					ans = max(ans, cnt);
					for (int i = idx; i < dia.size() - 1; i++) {
						if (dia[i] != dia[i + 1]) idx = i + 1;
						if (i == dia.size() - 2) flag = false;
					}
					break;
				}
				if (i == dia.size() - 2) flag = false;
			}
			ans = max(ans, cnt);
		}
		// 출력
		cout << "#" << test_case + 1 << " " << ans << endl;
	}
	return 0;
}
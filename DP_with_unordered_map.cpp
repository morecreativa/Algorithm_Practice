#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int N, int number) {
	int answer = 0;
	unordered_map<int, vector<int>> dp;
	dp[1].push_back(N);
	int digit = 1;
	for (int i = 2; i <= 8; i++) {
		digit *= 10;
		if (N*digit + dp[i - 1][0] == number) return i;
		dp[i].push_back(N*digit + dp[i - 1][0]);
		int x = 0, y = 0;
		for (int j = 1; j <= i - 1; j++) {
			for (int m = 0; m < dp[j].size(); m++)
				for (int n = 0; n < dp[i - j].size(); n++) {
					x = dp[j][m];
					y = dp[i - j][n];
					for (int p = 1; p <= 4; p++) {
						int temp = 0;
						switch (p) {
						case 1: temp = x + y; break;
						case 2: temp = x - y; break;
						case 3: temp = x * y; break;
						case 4: temp = x / y; break;
						}
						if (temp < 1) continue;
						else if (temp == number) return i;
						else dp[i].push_back(temp);
					}
				}
		}
	}

	return -1;
}

int main() {
	int answer = solution(5, 3600);
	cout << answer << endl;
}
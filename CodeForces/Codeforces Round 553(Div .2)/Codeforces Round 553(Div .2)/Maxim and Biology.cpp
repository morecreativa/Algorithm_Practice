#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define INF 9876654321
int ans = INF;
const string origin = "ACTG";
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n - 3; i++) {
		int temp = 0;
		for (int j = i; j < 4 + i; j++)
		{
			//just count & find it
	
			int for_temp = s[j] - origin[j - i];
			if (for_temp < 0) for_temp *= -1;
			if (for_temp > 13) for_temp = 26 - for_temp;
			temp += for_temp;
		}
		ans = min(temp, ans);
	}
	cout << ans;
	return 0;
}
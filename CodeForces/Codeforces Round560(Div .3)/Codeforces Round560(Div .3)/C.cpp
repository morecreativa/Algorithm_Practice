#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie();
	int n;
	string s;
	cin >> n;
	cin >> s;
	string ans = "";
	int idx = 0;
	while (idx < n)
	{
		ans += s[idx];
		char c = s[idx];
		idx++;
		if (ans.size() % 2 == 1)
		{
			while (idx < n&&s[idx] == c) idx++;
		}
	}
	if (ans.size() % 2 == 1) ans.pop_back();
	cout << s.size() - ans.size() << endl;
	cout << ans;
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str(n, 0);
	int temp_pal = (n - 11) / 2 + 1;
	int temp_len = temp_pal * 2 - 1;
	int cnt = 0;
	FOR(i, n)
	{
		cin >> str[i];
		if (i >= temp_len) continue;
		else if (i < temp_len&&str[i] == '8')cnt++;
	}
	if (cnt < temp_pal) cout << "NO";
	else cout << "YES";

	return 0;
}
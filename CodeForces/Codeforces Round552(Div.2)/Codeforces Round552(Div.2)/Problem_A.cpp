#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c;
	int ans[4];

	for (int i = 0; i < 4; i++)cin >> ans[i];
	sort(ans, ans + 4);
	a = ans[3] - ans[2];
	b = ans[0] - a;
	c = ans[1] - a;
	cout << a << ' ' << b << ' ' << c;
	return 0;
}
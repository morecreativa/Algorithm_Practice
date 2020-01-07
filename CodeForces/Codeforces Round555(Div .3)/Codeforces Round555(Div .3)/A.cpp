#include <iostream>

#define MAX 1000000000
#define ll long long

using namespace std;

int main()
{
	ll n;
	ll ans = 1;
	cin >> n;
	while (n >= 10)
	{
		n++;
		if (n % 10 == 0) while (n % 10 == 0) n = n / 10;
		ans++;
	}
	ans -= 1;
	cout << ans + 9;
	return 0;
}

// 10 11 12 13 14 15 16 17 18 19 2 3 4 5 6 7 8 9 1
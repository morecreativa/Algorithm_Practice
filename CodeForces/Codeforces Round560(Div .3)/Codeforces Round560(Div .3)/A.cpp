#include <iostream>
#include <vector>

#define MAX 200001
#define ll long long

using namespace std;

int main()
{
	ll n, x, y, cnt = 0;;
	cin >> n >> x >> y;
	int num[MAX] = { 0, };
	for (ll i = 0; i < n; i++)
		scanf("%1d", &num[i]);
	//for (int i = 0; i < n; i++) cout << num[i];
	for (ll i = n - 1; i >= n - x; i--)
	{
		if (i == n - y - 1)
		{
			if (num[n - y - 1] != 1) cnt++;
		}
		else
		{
			if (num[i]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
#include <iostream>
#include <vector>

#define MAX 200001
#define ll long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(false);
	ll n;
	cin >> n;
	ll cnt = 0;
	bool check[MAX] = { 0, };
	for (ll i = 0; i < n; i++)
	{
		ll temp = 0;
		cin >> temp;
		if (!check[temp]) {
			cnt++;
			check[temp] = true;
		}
	}
	cout << cnt;
	return 0;
}
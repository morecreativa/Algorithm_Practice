#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MAX 200000
typedef pair<ll, pair<ll, int>> pi;

int main()
{
	ll n, k;
	cin >> n >> k;
	vector<pi> vec;
	for (ll i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		pi p1 = make_pair(i + 1, (temp, 0));
	}
	return 0;
}
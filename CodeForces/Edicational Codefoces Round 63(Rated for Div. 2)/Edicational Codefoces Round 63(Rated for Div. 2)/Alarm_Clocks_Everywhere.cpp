
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
	ll tmp, n;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	
	ll n, m;
	cin >> n>> m;
	vector<ll> x(n, 0);
	vector<ll> p(m, 0);
	for (ll i = 0; i < n; i++) cin >> x[i];

	ll k = x[0];
	ll temp = x[1] - x[0];
	for (ll i = 1; i < n; i++)
	{
		ll tmp = x[i] - x[i - 1];
		temp = gcd(temp, tmp);
	}

	for (ll j = 0; j < m; j++) {
		cin >> p[j];
		if (temp%p[j]==0) {
			cout << "YES" << endl << x[0] << ' ' << j + 1;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
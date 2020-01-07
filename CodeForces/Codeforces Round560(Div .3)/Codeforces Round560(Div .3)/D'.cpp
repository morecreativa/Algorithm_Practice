#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000000
#define ll long long

int main()
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;
		vector<ll> div(n, 0);
		for (int i = 0; i < n; i++)	cin >> div[i];
		sort(div.begin(), div.end());
		ll temp = div.front()*div.back();
		bool flag = false;
		for (int i = 0; i < n; i++)
			if (temp%div[i] != 0)
			{
				flag = true;
				break;
			}
		if (flag) { cout << "-1" << endl;	continue; }
		// all div[i]s are passed 
		// count div_number of temp
		ll i;
		ll temp_cnt = 0;
		for (i = 1; i*i < temp; i++)
			if (temp%i == 0) temp_cnt += 2;
		if (i*i == temp) temp_cnt++;
		if (temp_cnt - 2 == n) cout << temp << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
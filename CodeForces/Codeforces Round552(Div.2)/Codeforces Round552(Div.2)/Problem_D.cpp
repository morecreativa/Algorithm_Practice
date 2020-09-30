#include <iostream>
#include <vector>

int ans = 0;
using namespace std;

int main()
{
	int n, bb, aa;
	cin >> n >> bb >> aa;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		/*{
			int temp = 0;
			cin >> temp;
			v.push_back(temp);
		}*/
		cin >> v[i];
	int i = 0;
	int a = aa, b = bb;
	while (b > 0 || a > 0)
	{
		if (v[i] == 0)
		{
			if (a > 0)
			{
				a--;
				ans++;
			}
			else {
				b--; if (b < 0)break;
				ans++;
			}
		}
		else
		{
			if (a == aa)
			{
				a--;
				ans++;
			}
			else
			{
				if (b > 0)
				{
					b--;
					a++;
					ans++;
				}
				else
				{
					a--;
					ans++;
				}
			}
		}
		if (i == n - 1) break;
		i++;
	}
	cout << ans;
	return 0;
}
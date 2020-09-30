#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define MAX 20000

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[10];
	for (int i = 1; i <= 9; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (s[i] - '0' < a[s[i] - '0'])
		{
			while (i < n&&s[i] - '0' <= a[s[i] - '0'])
			{
				s[i] = char(a[s[i] - '0'] + '0');
				i++;
			}
			break;
		}
	}
	cout << s;
	return 0;
}
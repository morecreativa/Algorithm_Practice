#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int i;
	cin >> n;
	for (i = 1; i*i < n; i++)
		if (n%i == 0) cnt += 2;
	if (i*i == n) cnt++;
	cout << cnt;
	return 0;
}
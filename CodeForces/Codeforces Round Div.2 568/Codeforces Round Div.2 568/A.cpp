#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int sum = 0;
	vector<int> a(3, 0);
	for (int i = 0; i < 3; i++) cin >> a[i];
	int d; cin >> d;
	sort(a.begin(), a.end());

	/*
	2 5 6 3
	1 3 5 6 -> 1 7 5 -> 1 5 7 -> 1 7 7 -> 1 7 13
	*/
	for (int i = 0; i < 2; i++)
	{
		int temp = a[i+1] - a[i]; if (temp < 0) temp *= -1;
		int temptemp = temp - d; if (temptemp < 0)
		{
			temptemp *= -1;
			sum += temptemp;
		}
	}
	
	cout << sum;
	return 0;
}
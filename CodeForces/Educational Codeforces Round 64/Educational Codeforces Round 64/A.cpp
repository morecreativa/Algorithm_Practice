#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parell_check(int cur,int next)
{
	int count = 0;
	if (cur == 1)
	{
		if (next == 2) return count = 3;
		else if (next == 3) return count = 4;
	}
	if (cur == 2)
	{
		if (next == 1) return count = 3;
		else if (next == 3) return count;
	}
	if (cur == 3)
	{
		if (next == 1) return count = 4;
		else if (next == 2) return count;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	
	// 평행이 존재하면 infinite
	int n;
	int jbc = 0;
	int answer = 0;
	cin >> n;
	vector<int> qt;
	// push elements in queue
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		qt.push_back(temp);
		if (i == 0) continue;
		if (i >= 2 && qt[i] == 2)
			if (qt[i - 1] == 1 && qt[i - 2] == 3) jbc++;
		if (i >= 1 && qt[i] == qt[i - 1])
		{
			cout << "Infinite" << endl;
			return 0;
		}
		int tt = parell_check(qt[i - 1], qt[i]);
		if (tt == 0)
		{
			cout << "Infinite" << endl;
			return 0;
		}
		answer = answer + tt;
	}
	cout << "Finite" << endl << answer - jbc;
	qt.clear();
	return 0;
}
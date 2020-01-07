#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;

	int num[100] = { INF, };
	vector<int> n;

	for (int i = 0; i < cnt; i++)	cin >> num[i];
	sort(num, num + cnt);

	n.push_back(num[0]);
	for (int i = 0; i < cnt; i++)
		if (num[i] != n.back()) n.push_back(num[i]);
	if (n.size() > 3) {
		cout << "-1";
		return 0;
	}
	switch (n.size())
	{
	case 1:
		cout << "0";
		break;
	case 2:
	{
		int temp1 = n.back() - n.front();
		if (temp1 % 2 == 1) cout << temp1;
		else cout << temp1 / 2;
	}
		break;
	case 3:
	{	int temp = n.back() - n.front();
	if (temp % 2 == 1) cout << "-1";
	else
	{
		temp = temp / 2;
		if (n[1] == n[0] + temp) cout << temp;
		else cout << "-1";
	}
	}
		break;
	}
	return 0;
}
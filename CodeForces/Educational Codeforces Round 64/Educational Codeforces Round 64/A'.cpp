

/*
	if문을 싹 날릴 수 있음
	int data[3][3] = { {0,3,4},{3,0,-1},{4,-1,0 } };
*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int answer = 0;
	int temp = 0;
	vector<int> m(n, 0);
	for (int i = 0; i < n; i++)
	{
		int temp_ans = 0;
		cin >> m[i];
		if (i == 0) continue;
		if (i >= 2 && m[i] == 2)
			if (m[i - 1] == 1 && m[i - 2] == 3) ++temp;
		if (m[i] == m[i - 1])
		{
			cout << "Infinite";
			return 0; 
		}
		if (m[i] == 1)
		{
			if (m[i - 1] == 2) temp_ans = 3;
			else if (m[i - 1] == 3) temp_ans = 4;
		}
		else if (m[i] == 2)
		{
			if (m[i - 1] == 1) temp_ans = 3;
			else if (m[i - 1] == 3)temp_ans = 0;
		}
		else if (m[i] == 3)
		{
			if (m[i - 1] == 1) temp_ans = 4;
			else if (m[i - 1] == 2) temp_ans = 0;
		}
		if (temp_ans == 0)
		{
			cout << "Infinite";
			return 0;
		}
		answer += temp_ans;
	}

	cout << "Finite" << endl << answer - temp;
	return 0;
}
// iterator practice
// vector container with iterator

#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int idx;
	int temp = 0;
	cin >> n;
	vector<int>visit(n, 0);
	vector<int>::iterator iter = visit.begin();
	FOR(i, n)
	{
		cin >> visit[i];
		if (temp < visit[i])
		{
			temp = visit[i];
			idx = i;
		}
	}
	iter = visit.begin() + idx;
	cout << temp << endl;
	cout << *iter << endl;

	vector<int> visit(n, 0);
	vector<int>::iterator iter = visit.begin();
	iter = visit.begin() + idx;
	cout << temp << endl;
	cout << *iter << endl;
	FOR(i, n)
	{
		cin >> visit[i];
		if (temp < visit[i])
		{
			temp = visit[i];
			idx = i;
		}
	}
	/*
	6
	2 3 1 6 5 4
	*/

	//int cnt;
	//bool count = false;
	//for (int i = 0; i < n; i++)
	//{
	//	int push_v;
	//	cin >> push_v;
	//	visit.push_back(push_v);
	//	//cin >> visit[i];
	//	if (temp < visit[i])
	//	{
	//		temp = visit[i];
	//		iter = visit.end() - 1;
	//		count = true;
	//	}
	//}
	////for (int i = 0; i < n; i++) cout << visit[i] << ' ';
	//cout << "for loop end" << ' ' << count << endl;
	//cout << *iter << endl;
	//iter = visit.erase(iter-1, iter + 2);

	//for (int i = 0; i < visit.size(); i++)
	//{
	//	cout << visit[i];
	//}
	//cout << endl << visit.size() << *iter;
	return 0;
}
#include <iostream>
#include <algorithm>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n, m, h;
	int nn[100];
	int mm[100];
	int map[100][100];
	cin >> n >> m >> h;

	FOR(x, m) cin >> mm[x];
	FOR(x, n) cin >> nn[x];

	//최소값만 출력하면 됨.
	FOR(x, n)
		FOR(y, m)
	{
		cin >> map[x][y];
		if (map[x][y] == 0)continue;
		if (map[x][y] == 1)
		{
			map[x][y] = min(mm[y], nn[x]);
		}
	}
	FOR(x, n) {
		FOR(y, m)
			cout << map[x][y] << ' ';
		cout << endl;
	}
	return 0;
}
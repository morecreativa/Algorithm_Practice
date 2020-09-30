#include <iostream>
#include <vector>
#include <string>

#define FOR(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

int main()
{
	int h, w; cin >> h >> w;
	vector<string> map(h);
	vector<vector<bool>> check(h, vector<bool>(w, false));
	FOR(i, h) cin >> map[i];
	/*
	1. Find Center
	2. ���Ͱ� ��ã������ flag=false ���� �� ä�� cout<< "NO";l
	3. ���� ã���� �� �Ʒ��� �� �˻� -> �˻� �ϸ鼭 check �迭 1�� ġȯ
	4.
	*/

	bool find_center = false;

	FOR(i, h)
		FOR(j, w)
	{
		if (i == 0 || j == 0 || i == h - 1 || j == w - 1) continue;
		if (map[i][j] == '*' && map[i + 1][j] == '*' && map[i - 1][j] == '*' && map[i][j + 1] == '*' && map[i][j - 1])
		{
			find_center = true;
			check[i][j] = true;
			// ã��
			int upper = i - 1, down = i + 1, rightside = j + 1, leftside = j - 1;
			while (map[upper][j] == '*') { check[upper][j] = true;	upper--; if (upper < 0) break; }
			while (map[down][j] == '*') { check[down][j] = true; down++; if (down > h - 1) break; }
			while (map[i][rightside] == '*') { check[i][rightside] = true; rightside++; if (rightside > w - 1) break; }
			while (map[i][leftside] == '*') { check[i][leftside] = true; leftside--; if (leftside < 0) break; }
			//check
			FOR(i2, h)
				FOR(j2, w)	if (check[i2][j2] == 0 && map[i2][j2] == '*') { cout << "NO"; return 0; }
		}
	}
	if (!find_center) { cout << "NO"; return 0; }
	cout << "YES";
	return 0;
}
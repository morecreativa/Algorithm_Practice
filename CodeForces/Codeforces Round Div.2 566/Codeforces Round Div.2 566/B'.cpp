#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int h, w; cin >> h >> w;
	vector<string> map(h);
	vector<vector<bool>> shouldbeone(h, vector<bool>(w, false));
	for (int i = 0; i < h; i++) cin >> map[i];
	bool full_flag = false;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			//���� ���� ó��
			if (full_flag) break;
			if (map[i][0] == '*' || map[i][w - 1] == '*') { cout << "NO"; return 0; };
			if (j != 0 && map[i][j] == '*')
			{
				int x = i, y = j;
				bool side_flag = false;

				while (map[x][y] == '*')
				{
					shouldbeone[x][y] = true;
					if (map[x][y - 1] == '*' || map[x][y + 1] == '*')
					{
						//side_flag ==true �ε��� �ұ��ϰ� �ٽ� �翷�� ���� �����Ǹ�,
						if (side_flag) { cout << "NO"; return 0; }
						if (map[x][y - 1] != map[x][y + 1]) { cout << "NO"; return 0; }
						else
						{
							int rightside = y + 1, leftside = y - 1;
							//������ �������� �� �Ʒ� �˻�
							while (map[x][rightside] == '*')
							{
								shouldbeone[x][rightside] = true;
								if (map[x + 1][rightside] == '*' || map[x - 1][rightside] == '*') { cout << "NO"; return 0; }
								rightside++; if (rightside > w - 1) break;
							}
							//���� ���� ���Ʒ� �˻�
							while (map[x][leftside] == '*')
							{
								shouldbeone[x][leftside] = true;
								if (map[x + 1][leftside] == '*' || map[x - 1][leftside] == '*') { cout << "NO"; return 0; }
								leftside--; if (leftside < 0) break;
							}
							side_flag = true;
							if (map[x + 1][y] != '*') { cout << "NO"; return 0; }
						}
					}
					++x; if (x > h - 1) break;
				}
				if (!side_flag) { cout << "NO"; return 0; }
				//�� �˻��ߴµ��� �ұ��ϰ� �ٸ� ���� ���� �ÿ�,
				for (int i2 = 0; i2 < h; i2++)
					for (int j2 = 0; j2 < w; j2++)
					{
						if (shouldbeone[i2][j2] == 0 && map[i2][j2] == '*')
						{
							cout << "NO";
							return 0;
						}
					}
				full_flag = true;
			}
		}
	if (full_flag) cout << "YES";
	else cout << "NO";
	return 0;
}
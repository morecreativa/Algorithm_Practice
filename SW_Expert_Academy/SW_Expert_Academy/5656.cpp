//5656 벽돌깨기

#include <iostream>

using namespace std;

int ans = INT32_MAX;
int map[15][12];
int n, w, h;

void mapremove(int cx, int cy)
{
	int mp = map[cx][cy];
	map[cx][cy] = 0;
	if (mp == 1) return;
	for (int a = cx - mp + 1; a <= cx + mp - 1; a++)
	{
		if (a >= 0 && a <= h - 1 && map[a][cy] != 0 && a != cx) mapremove(a, cy);
	}
	for (int b = cy - mp + 1; b <= cy + mp - 1; b++)
	{
		if (b >= 0 && b <= w - 1 && b != cy && map[cx][b] != 0) mapremove(cx, b);
	}

	return;
}
void pull()
{
	for (int i = 0; i < w; i++)
		for (int j = h - 1; j >= 0; j--) {
			if (map[j][i] == 0)
			{
				for (int x = j - 1; x >= 0; x--)
					if (map[x][i] != 0)
					{
						map[j][i] = map[x][i];
						map[x][i] = 0;
						break;
					}
			}

		}
	return;
}

void lego(int i)
{
	if (i == n) {
		int temp = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (map[i][j] != 0)temp++;
		if (ans > temp)ans = temp;
		return;
	}
	int tmap[15][12];
	for (int x = 0; x < h; x++)
		for (int y = 0; y < w; y++)
			tmap[x][y] = map[x][y];

	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
		{
			if (map[y][x] != 0)
			{
				mapremove(y, x);
				pull();
				lego(i + 1);
				for (int i = 0; i < h; i++)
					for (int j = 0; j < w; j++)
					{
						map[i][j] = tmap[i][j];
					}
				break;
			}
		}
}

int main()
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n >> w >> h;
		ans = INT32_MAX;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		lego(0);
		if (ans == INT32_MAX) ans = 0;
		cout << '#' << test_case + 1 << ' ' << ans << endl;
		//초기화 작업
	}

	return 0;
}
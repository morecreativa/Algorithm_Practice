//5646 원자소멸 시뮬레이션

#include <iostream>
#include <queue>
#include <string.h>

#define MAX 4001

using namespace std;

int ans;
int map[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

typedef struct {
	int px, py, dist, erg;
}atom;

bool range_chk(int cx, int cy)
{
	bool finished = false;
	if (cx >= 0 && cx <= 4000 && cy >= 0 && cy <= 4000) finished = true;
	//cout << finished << endl;
	return finished;
}

int main()
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n;
		queue<atom>q;
		ans = 0;
		memset(map, 0, sizeof(map));
		cin >> n;
		for (int a = 0; a < n; a++)
		{
			int x, y, d, e;
			cin >> x >> y >> d >> e;
			q.push({ (x + 1000) * 2,(y + 1000) * 2,d,e });
			map[2 * (y + 1000)][2 * (x + 1000)] = e;
		}
		while (!q.empty())
		{
			atom cur_atom = q.front();
			q.pop();

			if (map[cur_atom.py][cur_atom.px] > cur_atom.erg)
			{
				//cout << map[cur_atom.py][cur_atom.px] << endl;
				ans += map[cur_atom.py][cur_atom.px];
				map[cur_atom.py][cur_atom.px] = 0;
				continue;
			}
			else if (map[cur_atom.py][cur_atom.px] == 0)	continue;

			map[cur_atom.py][cur_atom.px] = 0;

			atom nxt_atom = cur_atom;
			nxt_atom.px = cur_atom.px + dx[cur_atom.dist];
			nxt_atom.py = cur_atom.py + dy[cur_atom.dist];

			if (range_chk(nxt_atom.px, nxt_atom.py))
			{
				if (map[nxt_atom.py][nxt_atom.px] == 0)
				{
					map[nxt_atom.py][nxt_atom.px] = cur_atom.erg;
					q.push(nxt_atom);
				}
				else map[nxt_atom.py][nxt_atom.px] = map[nxt_atom.py][nxt_atom.px] + nxt_atom.erg;
			}
		}
		cout << '#' << test_case + 1 << ' ' << ans << endl;
	}
	return 0;
}
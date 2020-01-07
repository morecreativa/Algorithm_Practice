#include <iostream>
#include <vector>

using namespace std;
int n;
char map[50][50];
bool chk(int cx,int cy)
{
	if (map[cx + 1][cy] == '.') map[cx + 1][cy] = '#';
	else return false;
	if (map[cx + 2][cy] == '.')map[cx + 2][cy] = '#';
	else return false;
	if (map[cx + 1][cy - 1] == '.')map[cx + 1][cy - 1] = '#';
	else return false;
	if (map[cx + 1][cy + 1] == '.')map[cx + 1][cy + 1] = '#';
	else return false;

	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '.') {
				if (j == 0 || j == n - 1 || i == n - 1) {
					cout << "NO";
					return 0;
				}
				if (chk(i, j) == true) continue;
				else
				{
					/*cout << i << j << endl;
					for (int x = 0; x < n; x++)
					{
						for (int y = 0; y < 3; y++)
						{
							cout << map[x][y];
						}
						cout << endl;
					}*/
					cout << "NO";
					return 0;
				}
			}
		}
	cout << "YES";
}
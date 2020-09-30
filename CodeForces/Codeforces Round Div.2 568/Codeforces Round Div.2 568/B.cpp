#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)

bool back_char(int w, int h, const string origin, const string error)
{
	bool flag = false;

	if (origin[w] == error[h])
	{
		int cnto = 0, cnte = 0;
		// push idx when next char is different from origin
		while (origin[w] == origin[w + 1] && w < origin.size()) { w++; cnto++; }
		while (error[h] == error[h + 1] && h < error.size()) { h++; cnte++; }
		if (cnto > cnte) return false;
		w++;
		h++;
		if (w == origin.size())
		{
			if (h<error.size()&&origin[w - 1] != error[h]) return false;
			else return true;
		}
		else if (w != origin.size() && h == error.size()) return false;
		flag = back_char(w, h, origin, error);
		if (!flag) return false;
	}
	else  return false;
}

int main()
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		string origin, error;
		cin >> origin >> error;
		if (error.size() < origin.size()) { cout << "NO" << endl; continue; }

		bool flag = back_char(0, 0, origin, error);
		/*cout << flag << endl;*/
		if (flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX 30000
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	queue<char>open;
	queue<char>close;
	if (n % 2 == 1) { cout << ":("; return 0; }
	FOR(i, n) if (s[i] == '(') open.push('(');
	//cout << open.size();
	int idx = 0;

	if (s[idx] != '(')
	{
		if(s[idx]==')'){ cout<<":("; return 0;}
		s[idx] = '('; open.push('(');
	}
	if (open.size() > n / 2) { cout << ":("; return 0; }
	close.push(')');
	while (!close.empty())
	{
		if (s[idx] == '?')
		{
			if (open.size() < n / 2) {
				s[idx] = '(';
				open.push('(');
				close.push(')');
			}
			else
			{
				s[idx] = close.front();
				close.pop();
			}
		}
		else if (s[idx] == ')') close.pop();
		else if (idx != 0 && s[idx] == '(') close.push(')');
		idx++;
	}
	if (idx != n) cout << ":(";
	else cout << s;
	return 0;
}
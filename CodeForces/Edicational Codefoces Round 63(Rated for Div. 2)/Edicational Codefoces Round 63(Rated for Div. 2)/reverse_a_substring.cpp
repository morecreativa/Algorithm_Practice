#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str(n, 0);

	for (int i = 0; i < n; i++) cin >> str[i];

	return 0;
}
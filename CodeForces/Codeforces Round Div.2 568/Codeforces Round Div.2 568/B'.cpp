#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string origin, error;

bool check()
{

}

int main()
{
	int test_case, T;
	cin >> T;
	for (test_case=0;test_case<T;test_case++)
	{
		int w = 0;
		int h = 0;
		cin >> origin >> error;
		if (origin.size() > error.size()) { cout << "NO" << endl; continue; }
		int n = origin.size();
		while (n--)
		{

		}
		/*
		1. w ,h idx 비교
		2. 하나씩 비교 -> 
		*/
	}
	return 0;
}
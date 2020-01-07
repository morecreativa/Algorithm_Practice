// A.Serval and Bus
// rating 1100

//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int ans = 0;
//
//int main()
//{
//	int n, t;
//	vector<int>s;
//	vector<int>d;
//	vector<int>temp_cnt;
//	cin >> n >> t;
//	if (n > 100 || n < 0 || t < 0 || t>100000) return EOF;
//	for (int i = 0; i < n; i++)
//	{
//		int S, D;
//		cin >> S >> D;
//		if (S > 100000 || D > 100000 || S < 0 || D < 0) return EOF;
//		s.push_back(S);
//		d.push_back(D);
//	}
//
//	/*for (int i = 0; i < s.size(); i++)
//	{
//		cout << s[i] << "  " << d[i] << endl;
//	}*/
//
//	queue<int>q;
//	q.push(s[0]);
//	int cnt = 0;
//	//bool finished = false;
//	//중간에 끼어드는값 생각해야함.
//	while (!q.empty())
//	{
//		int cur_time = q.front();
//		//cout << "cur_time" << cur_time << endl;
//		q.pop();
//		if (cur_time >= t)
//		{
//			
//		}
//		else
//		{
//			cnt++;
//			if ((cnt+1) > n)
//			{
//				int temp = cnt % n;
//				s[temp] = s[temp] + d[temp];
//				q.push(s[temp]);
//			}
//			else q.push(s[cnt]);
//		}
//	}
//	cout << ans;
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

int answer;

int main()
{
	int n, t;
	int temp = INT32_MAX;
	cin >> n >> t;
	vector<vector<int>>s;
	vector<int>d;
	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		int ts, td;
		vector<int>temp;
		cin >> ts >> td;
		temp.push_back(ts);
		d.push_back(td);
		s.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp = s[i][0];
		while (temp<t)
		{
			temp += d[i];
			s[i].push_back(temp);
		}
	}

	for (int i = 0; i < s.size(); i++)	ans.push_back(s[i].back());
	for (int a = 0; a < ans.size(); a++)
	{
		if (temp > ans[a])
		{
			temp = ans[a];
			answer = a + 1;
		}
		else continue;
	}
	cout << answer;
	s.clear();
	d.clear();
	ans.clear();
	return 0;
}
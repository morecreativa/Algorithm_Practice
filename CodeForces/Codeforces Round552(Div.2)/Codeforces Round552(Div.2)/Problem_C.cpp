//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <string>
//#define FOR(i,n) for(int i=0;i<n;i++)
//#define INF 987654321
//using namespace std;
//
//string date[7] = { "mon","tue","wed","thu","fri","sat","sun" };
//int ans = 0;
//
//int main()
//{
//	int food_start[3];
//	int cnt = 0;
//	for (int i = 0; i < 3; i++) cin >> food_start[i];
//
//	queue<string>dt;
//
//	FOR(i, 7)
//	{
//		//i is starting point.
//		int date_count = i;
//		int ans_temp = 0;
//		int food[3];
//		//initialized
//		FOR(j, 3)	food[j] = food_start[j];
//
//		//count pattern 
//		food[0] = food[0] / 3;		food[1] = food[1] / 2;		food[2] = food[2] / 2;
//		int temp = INF;
//		FOR(j, 3)temp = min(temp, food[j]);
//		//initialize one more time
//		FOR(j, 3)	food[j] = food_start[j];
//		if (temp != 0) 
//		{
//			ans_temp = temp * 7;
//			food[0] = food[0] - 3 * temp;	food[1] = food[1] - 2 * temp;	food[2] = food[2] - 2 * temp;
//		}
//
//		cnt = food[0] + food[1] + food[2];
//
//		//queue push
//		dt.push(date[date_count]);
//
//		while (!dt.empty())
//		{
//			string cur_date = dt.front();
//			dt.pop();
//			//loop break
//			if (cnt == 0)
//			{
//				cout << ans_temp;
//				return 0;
//			}
//
//			bool count_done = false;
//
//			//fish
//			if (cur_date == "mon" || cur_date == "thu" || cur_date == "sun")
//			{
//				if (food[0] > 0) {
//					food[0] -= 1;
//					cnt -= 1;
//					ans_temp += 1;
//					count_done = true;
//				}
//			}
//			//rabbit stew
//			else if (cur_date == "tue" || cur_date == "sat")
//			{
//				if (food[1] > 0) {
//					food[1] -= 1;
//					cnt -= 1;
//					ans_temp += 1;
//					count_done = true;
//				}
//			}
//			//chicken stake
//			else
//			{
//				if (food[2] > 0)
//				{
//					food[2] -= 1;
//					cnt -= 1;
//					ans_temp += 1;
//					count_done = true;
//				}
//			}
//			//push queue
//			if (count_done)
//			{
//				date_count++;
//				if (date_count == 7)date_count = 0;
//				dt.push(date[date_count]);
//			}
//		}
//		//cout << ans_temp << endl;
//		ans = max(ans, ans_temp);
//	}
//	cout << ans;
//	return 0;
//}

#include <iostream>
#include <algorithm>

#define ll long long
#define INF 987654321
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	ll food[3], temp = 0, ans = INF;
	FOR(i, 3) cin >> food[i];

	//assign variable & count pattern 
	ans = min(food[0] / 3, min(food[1] / 2, food[2] / 2));

	food[0] -= ans * 3;
	food[1] -= ans * 2;
	food[2] -= ans * 2;
	ans *= 7;

	//solution
	FOR(i,7)
	{
		ll tf = food[0], tr = food[1], tc = food[2], j = i, t = 0;
		while (tf >= 0 && tr >= 0 && tc >= 0)
		{
			// j means date
			if (j == 7) j = 0;
			t++;
			if (j == 0 || j == 3 || j == 6) tf--;
			else if (j == 2 || j == 6)tr--;
			else tc--;
			j++;
		}
		temp = max(temp, t - 1);
	}

	cout << ans + temp;
	return 0;
}
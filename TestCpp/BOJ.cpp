// BOJ. 1713

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define formy(i, r, l) for (int i = r; i <= (int)l; ++i)
#define pii pair<int, int>
#define sz(a) int((a).size())
#define ll long long
#define len(a) int((a).length())
 
int MAX_SIZE,cnt;
vector<int> arr(1001);
vector<int> answer;
void solve(){
	// student_id / (idx, recommended_cnt))
	map<int,pii> strMap;
	for(int i=0; i< cnt;++i){
		if(strMap.size()==MAX_SIZE){
			if(strMap.find(arr[i])==strMap.end()){
				priority_queue<pair<int,pii>,vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
				for(auto elem : strMap){
					//recommended_cnt / (idx, student_id)
					pq.push({elem.second.second,{elem.second.first,elem.first}});
				}
				pair<int,pii> cur=pq.top();
				strMap.erase(cur.second.second);
				strMap.insert({arr[i],{i,1}});
			}
			else{
				strMap[arr[i]].second++;
			}
		}
		else
			strMap.insert({arr[i],{i,1}});
	}

	for(auto temp : strMap)
		cout<<temp.first<<' ';
}

void input(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> MAX_SIZE;
	cin >> cnt;
	for(int i=0; i<cnt;++i)	 cin >> arr[i];
}

int main(){
	input();
	solve();
}

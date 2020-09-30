#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <sstream>
#include <stack>
#include <cstring>
 
using namespace std;
 
#define INF 987654321
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define formy(i,r,l) for(int i=r;i<=(int)l;++i)
#define pii pair<int,int>
#define sz(a) int((a).size())
#define mp make_pair
#define LL long long
#define len(a) int((a).length())
#define pb push_back
#define LL long long

vector<int> adj[51];

//find subtree
int numberOfsubree(int node){
	int ret=1;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int cur=q.front(); q.pop();
		for(auto x : adj[cur]){
			q.push(x);
			ret++;
		}
	}
	return ret;
}

int solution(int n, vector<vector<int>> edges){
	int answer=1;
	forn(i,sz(edges)){
		int start=edges[i][0];
		int end=edges[i][1];
		adj[start].pb(end);
	}
	queue<int> q; q.push(0);
	priority_queue<pii> pq;

	while(true){
		if(q.empty())
		while(!pq.empty()){
			q.push(pq.top().second);
			pq.pop();
			}
		while(!q.empty()){
			int start=q.front(); q.pop();
			for(auto x : adj[start]){
				pq.push({numberOfsubree(x),x});
			}
		}
		if(pq.empty()) break;
		pq.pop();
		answer+=pq.size();
	}
	return answer;
}
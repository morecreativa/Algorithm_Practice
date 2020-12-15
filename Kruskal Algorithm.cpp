#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
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

int link[100];  // Node Constructed with 100 Nodes

int find(int a){
    while(a!=link[a]) a=link[a];
    return a;
}

bool same(int a, int b){
    a=find(a);
    b=find(b);
    link[b]=a;
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    link[b]=a;
}

int main(){
    // pair constructed with start point, end point, weight
    vector<pair<int,pii>> edge;
    int minSpanningWeight=0;
    forn(i,100) link[i]=i;
    sort(edge.begin(),edge.end());  // sort
    forn(i,sz(edge)){
        int start=edge[i].first;
        int destination=edge[i].second.first;
        int w=edge[i].second.second;
        // Check the Cycle
        if(!same(start,destination)){
            Union(start,destination);
            minSpanningWeight+=w;
        }
    }
    cout<< minSpanningWeight<< endl;
    return 0;
}

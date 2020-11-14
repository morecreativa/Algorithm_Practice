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
#include <map>
#include <unordered_map>
 
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

#if 0

int countNumber[100001];

int solution(vector<int> &A){
    int ret=0;
    int maxNumber=-1;
    forn(i,100001) countNumber[i]=0;
    forn(i,A.size()){
        maxNumber=max(maxNumber,A[i]);
        countNumber[A[i]]++;
    }
    
    forn(i,A.size()) if(A[i] < maxNumber && countNumber[A[i]]!=0){
        ret+=(countNumber[A[i]] >= 2 ? 2:1);
        countNumber[A[i]]=0;
    }
    return ret+1;
}

#endif

#if 0

int solution(vector<int> &A){
    int ret=-1;
    // P+Q > R
    sort(A.begin(),A.end());
    for(int i=A.size()-1; i>=2; i--){
        int R=A[i], Q=A[i-1], P=A[i-2];
        ret=(P+Q > R ? max(P+Q+R,ret) : ret);
    }
    return ret;
}

#endif

#if 1

int findGcdWithUclid(int x,int y){
    while(y!=0){
    int z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int solution(vector<int> &X,vector<int> &Y){
    int ret=-1;
    unordered_map<string,int> strMap;
    for(int i=0;i<sz(X);++i){
        int numberGcd=findGcdWithUclid(X[i],Y[i]);
        string stringForKey=to_string(X[i]/numberGcd)+"/"+to_string(Y[i]/numberGcd);
        if(strMap.find(stringForKey)==strMap.end())
            strMap.insert({stringForKey,1});
        else strMap[stringForKey]++;
    }
    for(auto x : strMap) ret=max(ret,x.second);
    return ret;
}

#endif
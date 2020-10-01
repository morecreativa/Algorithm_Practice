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

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int test_case;
        scanf("%d",&test_case);
        string answer="";
        bool flag=true;
        vector<string> srtVector(test_case);
        for(auto &x : srtVector) cin>>x;
        sort(srtVector.begin(),srtVector.end());
        forn(i,sz(srtVector)-1){
            if(len(srtVector[i]) < len(srtVector[i+1]) && 
                srtVector[i]==srtVector[i+1].substr(0,len(srtVector[i]))){
                flag=false;
                break;
                }
        }
        answer= (flag ? "YES":"NO");
        cout<<answer<<endl;
    }
    return 0;
}

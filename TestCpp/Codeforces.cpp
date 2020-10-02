#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <sstream>
#include <map>
#include <bitset>
#include <stack>
#include <cstring>

using namespace std;

#define INF 987654321
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define formy(i, r, l) for (int i = r; i <= (int)l; ++i)
#define pii pair<int, int>
#define sz(a) int((a).size())
#define mp make_pair
#define LL long long
#define len(a) int((a).length())
#define pb push_back
#define LL long long

// Round 672
#if 0
int main(){
    int n; cin>>n;
    while(n--){
        int test_case; cin>>test_case;
        vector<int> arr(test_case);
        for(auto &x : arr) cin>>x; 
        int ok=1;   
        forn(i,sz(arr)-1){
            if(arr[i] <= arr[i+1]){
                ok=0;
                break;
            }
        }
        string answer=(ok ? "NO" : "YES");
        cout<<answer<<endl;
    }
    return 0;
}
#endif

#if 1
int countBit(unsigned int x){
    int cnt=0;
    while(x>0){
        cnt++;
        x >>=1;
    }
    return cnt;
}

int main(){
    LL n; cin>>n;
    while(n--){
        LL k; cin>>k;
        vector<LL> arr(k);
        for(auto &x : arr) cin>>x;
        map<LL,LL> strMap;
        forn(i,sz(arr)){
            int bitSize=countBit(arr[i]);
            // printf("%d %d\n",bitSize, arr[i]);
            if(strMap.find(bitSize)==strMap.end())
                strMap.insert({bitSize,1});
            else strMap[bitSize]++;
        }
        LL answer=0;
        for(auto x : strMap){
            // printf("%d %d\n",x.first,x.second);
            answer+=x.second*(x.second-1)/2;
        }cout<<answer<<endl;
    }
    return 0;
}

#endif
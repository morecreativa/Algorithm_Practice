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

#if 0
LL countBit(unsigned int x){
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
            LL bitSize=countBit(arr[i]);
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

#if 0

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int len,q;
		scanf("%d %d",&len,&q);
		vector<int> arr(len,0);
		for(auto &x : arr) cin>> x;
		arr.push_back(0);
 
		LL answer=0;
		int start=0,end=0;
		
		while(end<len){
			while(start<len-1 && arr[start]<arr[start+1]){
				++start;
				end=start;
			}
			while(end<=len-1 && arr[end]>arr[end+1]){
				++end;
			}
			answer+=arr[start]-arr[end];
			start=end;
		}
		printf("%lld\n",answer);
	}
	return 0;
}

#endif

#if 1

pii SHARK[20][20];
int head[20][20];
int dx[5]{0,-1,1,0,0};
int dy[5]{0,0,0,-1,1};
int chageDir[401][5][4];
int curDir[401];

int N,M,K;

bool rangeCheck(int nx,int ny){
    return (nx>=0 && nx<N && ny>=0 && ny<N);
}

int main(){
    cin>>N>>M>>K;
    forn(i,N) forn(j,N){
        cin >> SHARK[i][j].first;
        head[i][j]=SHARK[i][j].first;
        if(head[i][j]!=0) SHARK[i][j].second=K;
        else SHARK[i][j].second=0;
    }
    formy(i,1,M) cin>> curDir[i];
    formy(i,1,M){
        formy(j,1,4)
            forn(l,4){
                cin>>chageDir[i][j][l];
            }
    }

    int time=0;
    while(time <1000){
        time++;
        /* move with priority */
        queue<pii> q;
        forn(i,N) forn(j,N){
            if(head[i][j]!=0) q.push({i,j});
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second; q.pop();

            bool flag=true;  
            forn(l,4){
                int nx=i+dx[chageDir[head[i][j]][curDir[head[i][j]]][l]];
                int ny=j+dy[chageDir[head[i][j]][curDir[head[i][j]]][l]];
        
                if(rangeCheck(nx,ny) && SHARK[nx][ny].first==0){
                    flag=false;
                    if(head[nx][ny]==0) head[nx][ny]=head[i][j];
                    else if(head[nx][ny] > head[i][j]){
                        head[nx][ny]=head[i][j];
                        --M;
                    }
                    else if(head[nx][ny] < head[i][j]){
                        --M;
                    }
                    if(M==1){printf("%d",time); return 0;}
                    curDir[head[i][j]]=chageDir[head[i][j]][curDir[head[i][j]]][l];
                    head[i][j]=0;
                    break;
                }
            }
            /* 빈칸이 없을 때 */
            if(flag){
                forn(l,4){
                    int nx=i+dx[chageDir[head[i][j]][curDir[head[i][j]]][l]];
                    int ny=j+dy[chageDir[head[i][j]][curDir[head[i][j]]][l]];

                    if(rangeCheck(nx,ny) && SHARK[nx][ny].first==head[i][j]){
                        head[nx][ny]=head[i][j];
                        head[i][j]=0;
                        curDir[head[nx][ny]]=chageDir[head[nx][ny]][curDir[head[nx][ny]]][l];
                        break;
                    }
                }
            }
        }

        /* spend time */
        forn(i,N) forn(j,N)
            if(SHARK[i][j].second!=0) {
                SHARK[i][j].second--;
                if(SHARK[i][j].second==0) SHARK[i][j].first=0;
            }
        
        /* Final Plus Fragment */
        forn(i,N) forn(j,N){
            if(head[i][j]!=0) SHARK[i][j]={head[i][j],K};
        }
        
        if(M==1) break;
    }
    printf("%d",-1);
    return 0;
}

#endif

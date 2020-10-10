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

// 19237
#if 0
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

// 9252
#if 0

int dp[1001][1001];
string a,b;

void print(int x,int y){
    if(dp[x][y]==0) return;
    if(a[x-1]==b[y-1]){
        print(x-1,y-1);
        cout<<a[x-1];
    }else (dp[x-1][y] > dp[x][y-1] ? print(x-1,y) : print(x,y-1));
}

int main(){
    cin>>a;
    cin>>b;
    memset(dp,0,sizeof(dp));
    forn(i,len(a)){
        forn(j,len(b)){
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout<<dp[len(a)][len(b)]<<endl;
    print(len(a),len(b));
    return 0;
}

#endif

// 
#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 100001
int N, K;
int intMap[2000][2000];
bool visit[2000][2000];
int root[MAX_SIZE];
int dx[4] {-1,1,0,0};
int dy[4] {0,0,-1,1};

bool checkRange(int cx, int cy){
    return (0<=cx && cx<N && 0<=cy && cy<N);
}

int find_(int x) {
    if(root[x]==x) return x;
    else return find_(root[x]);
}

void union_(int x, int y){
    x=find_(x);
    y=find_(y);

    root[y]=x;
}

int main(){
    scanf("%d %d", &N, &K);
    //initialising
    memset(intMap,-1,sizeof(intMap));
    for(int i=0; i<MAX_SIZE; ++i) root[i]=i;

    //영토입력
    for(int i=0; i<K; ++i){
        int x,y;
        scanf("%d %d",&x, &y);
        intMap[x-1][y-1]=i;
    }

    //start
    bool flag=false; int answer=0;
    while(answer<3){
        memset(visit,0,sizeof(visit));
        //start
        for(int i=0; i<N; ++i){
            for(int j=0; j<N;++j){
                printf("%d ", intMap[i][j]);
            }printf("\n");
        }
        //end
        printf("\n");
        //union check
        flag=true;
        for(int i=0; i<K; ++i){
            if(root[i] != root[0]){
                flag=false;
                break;
            }
        }

        if(!flag) ++answer;
        else break;

        //span territory
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                visit[i][j]=1;
                for(int k=0; k<4; ++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    //MAP의 범위에서 벗어나면 continue
                    if(!checkRange(nx,ny)) continue;
                    // 1. 아무것도 없을 때 > 확장
                    if(intMap[nx][ny] == -1 && !visit[nx][ny]) {
                        intMap[nx][ny]=intMap[i][j];
                        visit[nx][ny]=1;
                    }
                    // 2. 다른 숫자가 있을 때 > find 비교 하고 다르면 union
                    else if(intMap[nx][ny] != -1 && find_(intMap[nx][ny]) == find_(intMap[i][i])) continue;
                    else union_(intMap[nx][ny], intMap[i][j]);
                } //map[i][j] 영역에 대해서 4방향 모두 살펴봄
            }
        } //spanning END
    }
    printf("%d", answer);
    return 0;
}

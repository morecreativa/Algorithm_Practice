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

// 5644 swexpertAcademy
#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// number, chargePower
vector<pair<int, int>> map[11][11];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };

void fillIn(int y, int x, int cost, int p, int idx) {
    map[x][y].push_back({ idx,p });
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            int xcost = (i - x < 0 ? x - i : i - x);
            int ycost = (j - y < 0 ? y - j : j - y);
            if (xcost + ycost <= cost)
                map[i][j].push_back({ idx,p });
        }
    }
    return;
}

int main() {
    // freopen("sample_input.txt", "r", stdin);
    int T; cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        // map init
        for (int i = 0; i < 11; ++i)
            for (int j = 0; j < 11; ++j) map[i][j].clear();
        int asum = 0, bsum = 0, divsum = 0;
        int M, A;
        cin >> M >> A;
        vector<int> dirA(M);    vector<int> dirB(M);
        for (auto& x : dirA) cin >> x;
        for (auto& x : dirB) cin >> x;

        for (int i = 1; i <= A; ++i) {
            int y, x, num, p;
            cin >> y >> x >> num >> p;
            fillIn(y, x, num, p, i);
        }
        pair<int, int> bcur = { 10,10 };
        pair<int, int> acur = { 1,1 };
        for (int i = 0; i <= M; ++i) {
            //check
            vector<pair<int, int>> numberOfAcharge, numberOfBcharge;
            //A
            if (map[acur.first][acur.second].size() != 0)
                numberOfAcharge = map[acur.first][acur.second];
            //B
            if (map[bcur.first][bcur.second].size() != 0)
                numberOfBcharge = map[bcur.first][bcur.second];
            //push sameNumber
            vector<pair<int, int>> sameNumber;
            for (int a = 0; a < (int)numberOfBcharge.size(); a++) {
                for (int b = 0; b < (int)numberOfAcharge.size(); b++) {
                    if (numberOfAcharge[b].first == numberOfBcharge[a].first)
                        sameNumber.push_back({ numberOfBcharge[a].first,numberOfBcharge[a].second });
                }
            }
            //Not in same Charger
            //if there is no same number just plus the number
            if (sameNumber.size() == 0) {
                int maxPower = 0;
                for (int a = 0; a < (int)numberOfAcharge.size(); ++a) {
                    maxPower = max(maxPower, numberOfAcharge[a].second);
                } asum += maxPower;
                maxPower = 0;
                for (int b = 0; b < (int)numberOfBcharge.size(); ++b) {
                    maxPower = max(maxPower, numberOfBcharge[b].second);
                } bsum += maxPower;
            }
            else {
                int midMax = 0;
                for (int a = 0; a < (int)sameNumber.size(); ++a)
                    midMax = max(midMax, sameNumber[a].second);
                int wholeMax = 0;
                for (int a = 0; a < (int)numberOfBcharge.size(); a++) {
                    for (int b = 0; b < (int)numberOfAcharge.size(); b++) {
                        if (numberOfAcharge[b].second != numberOfBcharge[a].second)
                            wholeMax = max(wholeMax, numberOfAcharge[b].second + numberOfBcharge[a].second);
                    }
                }
                divsum += max(midMax, wholeMax);
            }
            if (i == M) break;
            bcur = { bcur.first + dx[dirB[i]],bcur.second + dy[dirB[i]] };
            acur = { acur.first + dx[dirA[i]],acur.second + dy[dirA[i]] };
        }
        cout << '#' << test_case + 1 << ' ' << asum + bsum + divsum << endl;
    }
    return 0;
}

#endif 0

// 2383
#if 0

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct stair_info {
    int r;
    int c;
    int h;
};
struct person_info {
    int r;
    int c;
    int d;
    int t;
};
 
int n = 0;
int n_people = 0;
vector<person_info> person;
vector<stair_info> stair;
int ans = 987654321;
 
void sim() {
    vector<int> rest_time[2];
    int game_time = 0;
    for (int i = 0; i < n_people; i++) {
        rest_time[person[i].d].push_back(abs(person[i].r-stair[person[i].d].r) + abs(person[i].c - stair[person[i].d].c));
    }
 
    for (int i = 0; i < 2; i++) {
        if (rest_time[i].size()) {
            for (int a = 0; a < rest_time[i].size() - 1; a++) {
                for (int b = a + 1; b < rest_time[i].size(); b++) {
                    if (rest_time[i][a] > rest_time[i][b]) {
                        swap(rest_time[i][a], rest_time[i][b]);
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < rest_time[i].size(); a++) {
            if (a < 3) {
                rest_time[i][a] += (stair[i].h + 1);
            }
            else {
                if (rest_time[i][a] < rest_time[i][a - 3]) {
                    rest_time[i][a] = rest_time[i][a - 3] + stair[i].h;
                }
 
                else {
                    rest_time[i][a] += (stair[i].h + 1);
                }
            }
        }
    }
     
    for (int i = 0; i < 2; i++) {
        if (rest_time[i].size()) {
            if (game_time < rest_time[i][rest_time[i].size() - 1]) {
                game_time = rest_time[i][rest_time[i].size() - 1];
            }
        }
    }
 
    if (ans > game_time) ans = game_time;
}
 
void select(int idx) {
    if (idx == n_people) {
        sim();
    }
    else {
        person[idx].d = 0;
        select(idx + 1);
        person[idx].d = 1;
        select(idx + 1);
    }
}
 
int main() {
    int T = 0;
    int data_in = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        ans = 987654321;
        stair.clear();
        person.clear();
        scanf("%d", &n);
        for (int i= 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &data_in);
                if (data_in == 1) {
                    person.push_back({ i, j, 0, 0});
                }
                else if (data_in > 1) {
                    stair.push_back({ i,j, data_in });
                }
            }
        }
        n_people = person.size();
        select(0);
        printf("#%d %d\n", t, ans);
        fflush(stdout);
    }
    return 0;
}
About
#endif 0

//Fasoo Coding Test No 1.
#if 0
int arr[300001];

bool comp(const int &a, const int &b){
    return a>b;
}

int solution(string s, vector<int> nodeNumber){
    // Using Stack
    vector<int> answer;
    stack<int> st;
    forn(i,300001) arr[i]=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='{') st.push(i);
        else if(s[i]=='}'){
            arr[i]=st.top();
            arr[st.top()]=arr[i];
            st.pop();
        }
    }
    for(int i=0;i<nodeNumber.size();++i){
        answer.push_back(arr[nodeNumber[i]]);
    }
    sort(answer.begin(),answer.end(),comp);
    return answer;
}
#endif

//Fasoo Coding Test No 2.
#if 0
int solution(vector<string> BankNumber){
    vector<int> answer;
    return answer;
}
#endif

#if

[이친수]

■ 문제
    이친수란 숫자를 +0- 2진법으로 표현한것으로 +는 2의N승을 더하고, 0은 0, -는 2의N을 뺀다. (ex> 5는 +0+ 또는   ++-으로 표현가능함)
이친수는 0으로 시작할수 없음 (즉, +, -로 시작)

    [입력값] 
K = 이친수로 변경할 자연수
R = 이친수로 변경시 가능한 자릿수

    예) K가 1이고 R이 50일 경우
( + , -, 0 의 조합이 50개 가능)
    +
    +-
+--
+---
....
    +--- ... ---

K (-20억 ~ 20억)이 주어졌을때 R (50~5000) 의 자리로 이친수를 만들수 있는 경우의 수를 계산하시오
(테스트 입력 100개)

■ 테스트케이스
[입력]
11
    1 50
    2 50
    3 50
    4 50
    5 50
    6 50
    7 50
    8 50
    9 50
    0 50
    215 1000

    [출력]
    #1 50
    #2 49
    #3 97
    #4 48
    #5 143
    #6 95
    #7 142
    #8 47
    #9 187
    #10 1
    #11 28779+A1:N25


#endif

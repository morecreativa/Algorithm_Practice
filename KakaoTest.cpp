//1
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define formy(i, r, l) for (int i = r; i <= (int)l; ++i)
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string solution(string new_id) {
    string answer = "";
    //1
    for(int i=0; i < len(new_id); ++i) 
        if(new_id[i]<='Z' && new_id[i] >='A')
            new_id[i]=new_id[i]+('a'-'A');
    //2
    for(int i=0; i < len(new_id); )
        if(!((new_id[i]<='z' && new_id[i]>='a') || (new_id[i]>='0' && new_id[i]<='9')
            ||(new_id[i]=='-')||new_id[i]=='_'||new_id[i]=='.')){
                new_id.erase(new_id.begin()+i);
            }
        else ++i;
    //3
    for(int i=0; i<len(new_id)-1;)
        if(new_id[i]=='.' && new_id[i+1]=='.') new_id.erase(new_id.begin()+i);
        else ++i;
    //4
    if(new_id[0]=='.') new_id=new_id.substr(1,len(new_id));
    if(new_id[len(new_id)-1]=='.') new_id=new_id.substr(0,len(new_id)-1);
    //5
    if(new_id=="") new_id.append("a");
    //6
    if(len(new_id)>=16){
        new_id=new_id.substr(0,15);
        if(new_id[14]=='.') new_id.erase(14);
    }
    //7
    if(len(new_id)<=2) do{
        new_id+=(new_id[len(new_id)-1]);
    }while(len(new_id)!=3);
    return new_id;
}

//2
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

vector<string> bubunJiphap;
void dfs(string x, int flag[], int n)
{
	if (n == len(x))
	{
		string str = "";
		for (int i = 0; i < 10; ++i)
			if (flag[i])
				str += x[i];
		bubunJiphap.push_back(str);
		return;
	}

	flag[n] = 1;
	dfs(x, flag, n + 1);
	flag[n] = 0;
	dfs(x, flag, n + 1);
	return;
}

bool compare(const pair<string,int> &a, const pair<string,int> &b){
	if(len(a.first)==len(b.first)) return a.second < b.second;
	return len(a.first) < len(b.first);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	for (int i = 0; i < sz(orders); ++i)
	{
		string x = orders[i];
		sort(x.begin(), x.end());
		bubunJiphap.clear();
		int flag[11] = {0,};
		dfs(x, flag, 0);
		for (int j = 0; j < course[j]; ++j)
		{
			for (int k = 0; k < sz(bubunJiphap); ++k)
			{
				if (bubunJiphap[k].length() == course[j])
					answer.push_back(bubunJiphap[k]);
			}
		}
	}
	unordered_map<string, int> strMap;
	for (int i = 0; i < sz(answer); ++i)
		if (strMap.find(answer[i]) != strMap.end())
			strMap[answer[i]]++;
		else
			strMap.insert({answer[i], 1});
	answer.clear();
	vector<pair<string,int>> tempAnswer;
	for (auto x : strMap){
		if(x.second!=1) tempAnswer.push_back({x.first,x.second});
	}
	sort(tempAnswer.begin(), tempAnswer.end(), compare);
	int lencnt=0,cntcnt=0;
	for(int i=sz(tempAnswer)-1; i>=0; --i){
		if(lencnt!=len(tempAnswer[i].first)){
			answer.push_back(tempAnswer[i].first);
			lencnt=len(tempAnswer[i].first);
			cntcnt=tempAnswer[i].second;
		}
		else if(cntcnt == tempAnswer[i].second) answer.push_back(tempAnswer[i].first);
	}
	sort(answer.begin(), answer.end());
	return answer;
}

//3
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define formy(i, r, l) for (int i = r; i <= (int)l; ++i)
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> kakaoMap[3][2][2][2];
unordered_map<string,char> strMatches;

void initial(){
    strMatches.insert({"cpp",'0'}); strMatches.insert({"java",'1'}); strMatches.insert({"python",'2'});
    strMatches.insert({"backend",'0'}); strMatches.insert({"frontend",'1'});
    strMatches.insert({"junior",'0'}); strMatches.insert({"senior",'1'});
    strMatches.insert({"chicken",'0'}); strMatches.insert({"pizza",'1'});
    strMatches.insert({"-",'*'});
}

int howManyPerson(string x, int count){
    int ret=0;
    if(x[count]=='*'){
        switch (count){
            case 0:{ for(int i=0; i<3; ++i){
                x[count]=i+'0'; ret+=howManyPerson(x,count+1);
            }} break;
            case 1:{ for(int i=0; i<2; ++i){
                x[count]=i+'0'; ret+=howManyPerson(x,count+1);
            }} break;
            case 2:{ for(int i=0; i<2; ++i){
                x[count]=i+'0'; ret+=howManyPerson(x,count+1);
            }} break;
            case 3:{ for(int i=0; i<2; ++i){
                x[count]=i+'0'; ret+=howManyPerson(x,count+1);
            }} break;
            case 4:{ ret+=kakaoMap[x[0]-'0'][x[1]-'0'][x[2]-'0'][x[3]-'0'].size();
                     return ret; } break;
        }
    }
    else {
        if(count==4){
            int score=stoi(x.substr(count,len(x)));
            for(int i=0; i<kakaoMap[x[0]-'0'][x[1]-'0'][x[2]-'0'][x[3]-'0'].size(); ++i)
                if(kakaoMap[x[0]-'0'][x[1]-'0'][x[2]-'0'][x[3]-'0'][i] >= score) ret++;
            return ret;
        }
        else ret+=howManyPerson(x,count+1);
    }
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query)
{   
    initial();
    vector<int> answer;

    // makning DB table
    for(auto &x : info){
        string str[5], queryString="";
        stringstream(x) >> str[0] >> str[1] >> str[2] >> str[3] >> str[4];
        for(int i=0; i< 4; ++i) queryString+=strMatches[str[i]];
        kakaoMap[queryString[0]-'0'][queryString[1]-'0'][queryString[2]-'0'][queryString[3]-'0'].push_back(stoi(str[4]));
        // cout << queryString << endl;
    }
    
    for(auto &x : query){
        string str[5], _, queryString="";
        stringstream(x) >> str[0] >> _ >> str[1] >> _ >> str[2] >> _ >> str[3] >> str[4];
        // for(int i=0; i<5; ++i) cout<<str[i]<<(i!=4 ? ' ':'\n');
        for(int i=0; i<4; ++i) queryString+=strMatches[str[i]];
        queryString+=str[4];
        answer.push_back(howManyPerson(queryString,0));
        // cout << queryString << endl;
    }

    return answer;
}

//4
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define formy(i, r, l) for (int i = r; i <= (int)l; ++i)
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer=0x3f3f3f3f;
    --s, --a, --b;
    int dist[201][201]; memset(dist, 0x3f, sizeof(dist));
    for(int i=0; i<n; ++i) dist[i][i]=0;
    for(int i=0; i<sz(fares); ++i){
        int p=fares[i][0] -1, q=fares[i][1]-1;
        dist[p][q]=dist[q][p]=fares[i][2];
    }

    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    
    for(int i=0; i<n; ++i)
        answer=min<ll>(answer, (ll)dist[s][i]+dist[i][a]+dist[i][b]);
    return answer;
}

struct Node{
    int cost, pre, src, dest;
    Node(int cost, int pre, int src, int dest) : cost(cost), pre(pre), src(src), dest(dest) {}
};

struct NodeCompare{
    bool operator()(const Node &a, const Node &b){
        return a.cost + a.pre > b.cost + b.pre;
    }
};

void dijkstra(const int &n, const int &start, const vector<vector<int>>& nodes, vector<int>& costs){
    priority_queue<Node, vector<Node>, NodeCompare> pq;
    Node now(0,0,start,start);
    pq.push(now);
    while(!pq.empty()){
        now=pq.top();
        pq.pop();
        if(costs[now.dest]!=-1) continue;
        costs[now.dest] = ((costs[now.src] < 0) ? 0:costs[now.src]) + now.cost;
        for(int i=1; i<=n; ++i){
            if(now.dest != i && nodes[now.dest][i] != -1 && costs[i]==-1)
                pq.push(Node(nodes[now.dest][i],costs[now.dest], now.dest, i));
        }
    }
}

int solution2(int n, int s, int a, int b, vector<vector<int>> fares){
    vector<vector<int>> nodes(n+1, vector<int>(n+1,-1));
    vector<int> a_cost(n+1, -1), b_cost(n+1,-1), s_cost(n+1,-1);
    for(int i=1; i<=n; ++i) nodes[i][i]=0;
    for(auto fare : fares)
        nodes[fare[0]][fare[1]] = fare[2], nodes[fare[1]][fare[0]]=fare[2];
    dijkstra(n, a, nodes, a_cost);
    dijkstra(n, b, nodes, b_cost);
    dijkstra(n, s, nodes, s_cost);

    int answer=INF;
    for(int i=1; i<=n; ++i){
        if((a_cost[i] != -1) && (b_cost[i]!= -1) && (s_cost[i] != -1)){
            answer=min(answer, a_cost[i] + b_cost[i] + s_cost[i]);
        }
    }
    return answer;
}

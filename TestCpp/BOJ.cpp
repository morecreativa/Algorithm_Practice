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

// BOJ 5052
#if 0
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
#endif 

// Programmers Find Prime numbers
#if 0
bool isPrimeNumber(int x){
    if(x<=1) return 0;
    int answer=0;
    for(int i=1;i<=x;++i){
        if(x%i==0) {
            if(answer>2) return false;
            answer+=2;
        }
    }
    return true;
}
int solution(string numbers) {
    sort(numbers.begin(),numbers.end());
    int answer = 0;
    map<int,int> intMap;
    do{
        for(int i=1;i<=numbers.length();++i){
            int temp=stoi(numbers.substr(0,i));
            if(intMap.find(temp)==intMap.end()){
                intMap.insert({temp,1});   
                // if()
                if(isPrimeNumber(temp)){
                    answer++;
                }
            }else continue;
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    return answer;
}//next permutation don't show all permutation
#endif

// Programmers Carpet
#if 1
bool compare(const int &a , const int &b){
    return a>b;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i*i<=yellow;++i){
        if(yellow%i==0 && (i+yellow/i)*2+4==brown){
            answer.push_back(i+2);
            answer.push_back(yellow/i+2);
            sort(answer.begin(),answer.end(),compare);
            break;
        }
    }
    return answer;
}
#endif

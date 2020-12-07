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

#if 0
void solution(int numOfOrder, string *orderArr) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
  for(int i=0;i<numOfOrder;++i){
    string str=orderArr[i];
    for(int ii=0;ii!=str.length()-1;){
      if(str[ii]>='0' && str[ii]<='9' && str[ii+1]=='('){
        int end=ii;  while(str[end]=!')') end++;
        string loopStr=str.substr(ii+2,end-ii-1);
        for(int x=0;x<str[ii]-'0';++x) loopStr+=loopStr;
        str=str.substr(0,ii)+loopStr+str.substr(end+1,str.length());
        ii+=loopStr.length()*(str[ii]-'0');
      }else if(str[ii]>='A' && str[ii]<='Z' && str[ii+1]=='('){
        string plusStr="";
        int end=ii;  while(str[end]=!')') end++;
        string loopStr=str.substr(ii+2,end-ii-1);
        for(int x=0;x<loopStr.length();++x){
            plusStr+=(str[ii]+loopStr[x]);
        }
        str=str.substr(0,ii)+plusStr+str.substr(end+1,str.length());
        ii+=loopStr.length()+1;
      } else if(str[ii]>='0' && str[ii]<='9' && str[ii+1]>='A' && str[ii+1]<='Z'){
        string plusStr="";
        for(int x=0;x<str[ii]-'0';++x){
          plusStr+=str[ii+1];
        }
        str=str.substr(0,ii)+plusStr+str.substr(ii+2,str.length());
        ii+=str[ii]-'0'
      }
    }
  }
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
#endif

// MIRACOM FIRST
#if 1
/*
1. 3*3 arr
2. 4,2,1 time
3. sequential array about size
4. Minimum time
*/

int answer , N;
int size_[20];
int time_[20];

void solve(int temp,int idx){
  if(idx == N){
    answer=min(temp,answer);
    return;
  }
  if(temp > answer) return;
  int sizeFour=0, tempMaxTime=-1, FullSize=0;
  while(idx < N){
    tempMaxTime=max(tempMaxTime,time_[idx]);
    FullSize+=size_[idx]; if(FullSize > 9) break;
    if(size_[idx]==4){
      sizeFour++; 
      if(sizeFour > 1) break;
    }
    idx++;
    solve(temp+tempMaxTime, idx);
  }
  return;
}

int main(){
  int T;
  cin>>T;
  forn(test_case,T){
    cin>>N;
    answer=INF;
    forn(i,20) size_[i]=0;
    forn(i,20) time_[i]=0;
    forn(i,N) cin>>size_[i] >> time_[i];
    solve(0,0);
    cout<<'#'<<test_case+1<<' '<<answer<<endl;
  }
  return 0;
}

#endif
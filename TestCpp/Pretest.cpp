#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

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
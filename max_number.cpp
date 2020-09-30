#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	for (int i = 0; i < number.size(); i++) {
		while (!answer.empty() && answer.back() < number[i] && k > 0) {
			answer.pop_back();
			k--;
		}
		if (k == 0) { answer += number.substr(i, number.length() - i); break; }
		answer.push_back(number[i]);
	}

	return answer.substr(0, answer.size() - k);
}

string solution2(string number, int k) {
	
	for (int i = 0; i < number.size()-k; i++) {
		auto iter = max_element(number.begin() + i, number.begin() + i + k + 1);
		if (iter!=number.begin()+i) {
			number.erase(number.begin() + i, iter);
			k -= distance(number.begin() + i, iter);
		}
	}

	number.erase(number.end() - k, number.end());
	return number;
}
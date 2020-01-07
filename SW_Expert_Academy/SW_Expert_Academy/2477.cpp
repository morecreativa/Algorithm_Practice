#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define INF 987654321

struct Order {
	int period = 0;
	int p_idx = 0;
	bool visit = false;
};

struct Repair {
	int period = 0;
	int p_idx = 0;
	bool visit = false;
};

struct Person {
	int No = 0;
	int arrival_time = 0;
	int list = 0;
	int list_start_time = 0;
	int pair = 0; int pair_start_time = 0;
};

int Answer = 0;

int main() {
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		int n, m, k, A, B;
		cin >> n >> m >> k >> A >> B;
		vector<Order> O(n);
		vector<Repair> R(m);
		vector<Person> P(k + 1);

		FOR(i, n) { int temp; cin >> temp; O[i].period = temp; }
		FOR(i, m) { int temp; cin >> temp; R[i].period = temp; }
		FOR(i, k) { int temp; cin >> temp; P[i + 1].arrival_time = temp; P[i + 1].No = i + 1; }

		//FOR(i, k) FOR(j, k) {
		//	if (P[j].arrival_time > P[j + 1].arrival_time) {
		//		Person pp = P[j];
		//		P[j] = P[j + 1];
		//		P[j + 1] = pp;
		//	}
		//}

		queue<Person> oq;
		queue<Person> rq;

		FOR(i, k + 1) { if (i == 0)continue; oq.push(P[i]); }
		Person cur = oq.front();
		int t = 0;
		bool flag = true;
		while (!oq.empty() || !rq.empty() || flag) {
			flag = false;
			FOR(i, O.size()) if (O[i].visit) { flag = true; break; }
			FOR(j, R.size()) if (R[j].visit) { flag = true; break; }
			//check
			FOR(i, O.size()) if (O[i].visit &&
				(t - O[i].period - P[O[i].p_idx].list_start_time == 0)) {
				O[i].visit = false;
				rq.push(P[O[i].p_idx]);
			}
			FOR(i, R.size()) if (R[i].visit &&
				(t - R[i].period - P[R[i].p_idx].pair_start_time == 0)) {
				R[i].visit = false;
			}

			//Order
			if (!oq.empty()) {
				FOR(i, O.size()) {
					if (!O[i].visit&&t >= cur.arrival_time && !oq.empty()) {
						oq.pop();
						O[i].p_idx = cur.No;
						O[i].visit = true;
						P[O[i].p_idx].list_start_time = t;
						P[O[i].p_idx].list = i + 1;
						if (!oq.empty()) cur = oq.front();
					}
				}
			}

			//Repair
			if (!rq.empty()) {
				Person nxt = rq.front();
				FOR(i, R.size()) {
					if (!R[i].visit && !rq.empty()) {
						rq.pop();
						R[i].p_idx = nxt.No;
						R[i].visit = true;
						P[R[i].p_idx].pair_start_time = t;
						P[R[i].p_idx].pair = i + 1;
						if (!rq.empty()) nxt = rq.front();
					}
				}
			}
			t++;
		}

		// Missing Go Gaek Nim
		FOR(i, P.size()) {
			if (P[i].list == A && P[i].pair == B)
				Answer += P[i].No;
		}
		if (Answer == 0) Answer = -1;
		cout << '#' << test_case + 1 << ' ' << Answer << endl;
		Answer = 0;
	}
	return 0;
}
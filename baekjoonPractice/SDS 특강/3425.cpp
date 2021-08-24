#include <iostream>
#include <vector>
#include <stack>
#define ll long long
#define MAX 1000000000
using namespace std;
vector<string> v;
vector<ll> num_v;
stack<ll> s;
string cmd;
ll t, x;
/*
	에러
	1. 숫자가 부족해서 연산을 수행할 수 없을 때
	2. 0으로 나눴을 때(DIV, MOD)
	3. 연산 결과의 절댓값이 10^9를 넘어갈 때
	4. 모든 수행이 종료됐을 때 스택에 저장되어 있는 숫자가 1개가 아니라면
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 전체 loop
	while (1) {
		// 부분 loop
		while (1) {
			cin >> cmd;
			if (cmd == "NUM") {
				ll temp;
				cin >> temp;
				num_v.push_back(temp);
			}
			// end 입력 시 숫자 입력
			if (cmd == "END") {
				break;
			}
			// quit 입력 시 종료
			else if (cmd == "QUIT") {
				return 0;
			}
			v.push_back(cmd);
		}

		// 숫자 연산 시작
		cin >> t;
		while (t--) {
			bool flag = true;
			int num_idx = 0;
			cin >> x;
			if (x<-MAX || x>MAX) {
				flag = false;
				break;
			}
			s.push(x);
			for (string str : v) {
				//NUM X : X를 스택의 가장 위에 저장한다. (0 ≤ X ≤ 10^9)
				if (str == "NUM") {
					ll temp = num_v[num_idx++];
					
					if (temp > MAX) {
						flag = false;
						break;
					}
					s.push(temp);
				}
				//POP : 스택 가장 위의 숫자를 제거한다.
				else if (str == "POP") {
					if (s.empty()) {
						flag = false;
						break;
					}
					s.pop();
				}
				//INV : 첫 번째 수의 부호를 바꾼다. (42 -> - 42)
				else if (str == "INV") {
					if (s.empty()) {
						flag = false;
						break;
					}
					ll temp = s.top();
					s.pop();
					s.push(-temp);

				}
				//DUP : 첫 번째 숫자를 하나 더 스택의 가장 위에 저장한다.
				else if (str == "DUP") {
					if (s.empty()) {
						flag = false;
						break;
					}

					ll temp = s.top();
					s.push(temp);

				}
				//SWP : 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
				else if (str == "SWP") {
					if (s.size()<2) {
						flag = false;
						break;
					}

					ll first = s.top();
					s.pop();
					ll second = s.top();
					s.pop();

					s.push(first);
					s.push(second);
				}
				//ADD : 첫 번째 숫자와 두 번째 숫자를 더한다.
				else if (str == "ADD") {
					if (s.size() < 2) {
						flag = false;
						break;
					}
					ll res = s.top();
					s.pop();
					res += s.top();
					s.pop();
					if (res < -MAX || res > MAX) {
						flag = false;
						break;
					}
					s.push(res);
				}
				//SUB : 첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
				else if (str == "SUB") {
					if (s.size() < 2) {
						flag = false;
						break;
					}
					ll first = s.top();
					s.pop();
					ll second = s.top();
					s.pop();
					ll res = second - first;
					if (res < -MAX || res > MAX) {
						flag = false;
						break;
					}
					s.push(res);
				}
				//MUL : 첫 번째 숫자와 두 번째 숫자를 곱한다.
				else if (str == "MUL") {
					if (s.size() < 2) {
						flag = false;
						break;
					}
					ll res = s.top();
					s.pop();
					res *= s.top();
					s.pop();
					if (res < -MAX || res > MAX) {
						flag = false;
						break;
					}
					s.push(res);
				}
				//DIV : 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장한다.두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
				else if (str == "DIV") {
					if (s.size() < 2 || s.top() == 0) {
						flag = false;
						break;
					}
					ll first = s.top();
					s.pop();
					ll second = s.top();
					s.pop();
					ll res = second / first;
					if (res < -MAX || res > MAX) {
						flag = false;
						break;
					}
					s.push(res);
				}
				//MOD : 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장한다.두 번째 숫자가 피제수, 첫 번째 숫자가 제수이다.
				else if (str == "MOD") {
					if (s.size() < 2 || s.top() == 0) {
						flag = false;
						break;
					}
					ll first = s.top();
					s.pop();
					ll second = s.top();
					s.pop();
					ll res = second % first;
					if (res < -MAX || res > MAX) {
						flag = false;
						break;
					}
					s.push(res);
				}
			}

			if (s.size() != 1)
				flag = false;

			if (flag) {
				cout << s.top() << '\n';
			}
			else {
				cout << "ERROR\n";
			}
			while (!s.empty())
				s.pop();

		}

		cout << '\n';
		v.clear();
		num_v.clear();
	}
}
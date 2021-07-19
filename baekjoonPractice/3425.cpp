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
	����
	1. ���ڰ� �����ؼ� ������ ������ �� ���� ��
	2. 0���� ������ ��(DIV, MOD)
	3. ���� ����� ������ 10^9�� �Ѿ ��
	4. ��� ������ ������� �� ���ÿ� ����Ǿ� �ִ� ���ڰ� 1���� �ƴ϶��
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// ��ü loop
	while (1) {
		// �κ� loop
		while (1) {
			cin >> cmd;
			if (cmd == "NUM") {
				ll temp;
				cin >> temp;
				num_v.push_back(temp);
			}
			// end �Է� �� ���� �Է�
			if (cmd == "END") {
				break;
			}
			// quit �Է� �� ����
			else if (cmd == "QUIT") {
				return 0;
			}
			v.push_back(cmd);
		}

		// ���� ���� ����
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
				//NUM X : X�� ������ ���� ���� �����Ѵ�. (0 �� X �� 10^9)
				if (str == "NUM") {
					ll temp = num_v[num_idx++];
					
					if (temp > MAX) {
						flag = false;
						break;
					}
					s.push(temp);
				}
				//POP : ���� ���� ���� ���ڸ� �����Ѵ�.
				else if (str == "POP") {
					if (s.empty()) {
						flag = false;
						break;
					}
					s.pop();
				}
				//INV : ù ��° ���� ��ȣ�� �ٲ۴�. (42 -> - 42)
				else if (str == "INV") {
					if (s.empty()) {
						flag = false;
						break;
					}
					ll temp = s.top();
					s.pop();
					s.push(-temp);

				}
				//DUP : ù ��° ���ڸ� �ϳ� �� ������ ���� ���� �����Ѵ�.
				else if (str == "DUP") {
					if (s.empty()) {
						flag = false;
						break;
					}

					ll temp = s.top();
					s.push(temp);

				}
				//SWP : ù ��° ���ڿ� �� ��° ������ ��ġ�� ���� �ٲ۴�.
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
				//ADD : ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
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
				//SUB : ù ��° ���ڿ� �� ��° ���ڸ� ����. (�� ��° - ù ��°)
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
				//MUL : ù ��° ���ڿ� �� ��° ���ڸ� ���Ѵ�.
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
				//DIV : ù ��° ���ڷ� �� ��° ���ڸ� ���� ���� �����Ѵ�.�� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
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
				//MOD : ù ��° ���ڷ� �� ��° ���ڸ� ���� �������� �����Ѵ�.�� ��° ���ڰ� ������, ù ��° ���ڰ� �����̴�.
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
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> s;
int arr[100001];
int visited[100001];
int finished[100001];
void dfs(int n) {
	visited[n] = true;
	s.push(n);
	int next = arr[n];
	if (visited[next]) {
		if (!finished[next]) {
			while (!s.empty() && s.top() != next)
				s.pop();
			s.pop();
		}
	}
	else
		dfs(next);
	
	finished[n] = true;
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		arr[i] = 0;
		visited[i] = 0;
		finished[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		init(n);
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
			arr[i] = a;
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) 
				dfs(i);
		}
		int cnt = 0;
		while (!s.empty()) {
			s.pop();
			cnt++;
		}
		cout << cnt << '\n';
	}
}

//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//vector<vector<int> > v;
//stack<int> s;
//int visited[100001];
//int finished[100001];
//int n;
//void dfs(int n) {
//	visited[n] = true;
//	s.push(n);
//	for (int next : v[n]) {
//		if (visited[next]) {
//			if (finished[next])
//				continue;
//			else {
//				while (!s.empty() && s.top() != next)
//					s.pop();
//				s.pop();
//			}
//		}
//		else 
//			dfs(next);
//	}
//	finished[n] = true;
//}
//
//void init(int n) {
//	v.clear();
//	for (int i = 1; i <= n; i++) {
//		visited[i] = false;
//		finished[i] = false;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	int t;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		init(n);
//		v.resize(n + 1);
//		for (int i = 1; i <= n; i++) {
//			int a;
//			cin >> a;
//			v[i].push_back(a);
//		}
//
//		for (int i = 1; i <= n; i++) {
//			if (!visited[i]) {
//				dfs(i);
//			}
//		}
//		int cnt = 0;
//		while (!s.empty()) {
//			//cout << s.top() << ' ';
//			s.pop();
//			cnt++;
//		}
//		cout << cnt << endl;
//	}
//	
//}
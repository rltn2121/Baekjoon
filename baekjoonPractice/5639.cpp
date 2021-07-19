//#include <iostream>
//using namespace std;
//int tree[100001];
//void func(int root, int e) {
//
//	if (root < 0 || e < 0) return;
//	if (root == e) {
//		cout << tree[root] << '\n';
//		return;
//	}
//	
//
//	int right_root = root;
//
//	while (right_root <= e && tree[right_root] <= tree[root]) {
//		right_root++;
//	}
//
//	int left_end = right_root - 1;
//
//	// ���� �ڽ��� ����
//	if (!(left_end <= root)) {
//		func(root+1, left_end);
//	}
//
//	// ������ �ڽ��� ����
//	if (!(right_root > e)) {
//		func(right_root, e);
//	}
//
//	cout << tree[root] << '\n';
//	   
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	/*int x;
//	cin >> x;
//	int idx = 0;
//	while (x != EOF) {
//		tree[idx++] = x;
//		cin >> x;
//	}*/
//
//	int x;
//	int idx = 0;
//	while (cin >> x) {
//		tree[idx++] = x;
//	}
//	func(0, idx-1);
//}

#include <iostream>
using namespace std;
int tree[10001];
int idx = 1;

void func(int root, int e) {
	if (root > e) return;

	int mid = root + 1;
	while (mid <= e) {
		if (tree[mid] > tree[root])
			break;
		mid++;
	}

	// ���� ����Ʈ��
	func(root + 1, mid - 1);

	// ������ ����Ʈ��
	func(mid, e);

	cout << tree[root] << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	int idx = 0;
	while (cin >> x) {
		tree[idx++] = x;
	}
	func(0, idx - 1);
}
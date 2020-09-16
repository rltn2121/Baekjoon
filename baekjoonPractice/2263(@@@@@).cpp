#include <iostream>
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;
int n;
int pre[100000];
int in[100000];
int post[100000];
int inorder_idx[100001];
int idx = 0;
void preorder(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = post[post_end];
	pre[idx++] = root;
	int in_mid = inorder_idx[root];
	preorder(in_start, in_mid - 1, post_start, post_start + (in_mid - in_start)-1);
	preorder(in_mid+1, in_end, post_start + (in_mid - in_start), post_end - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n)
		cin >> in[i];
	rep(i, n)
		cin >> post[i];
	rep(i, n)
		inorder_idx[in[i]] = i;
	preorder(0, n - 1, 0, n - 1);
	rep(i, n)
		cout << pre[i] << ' ';
}

/*
15
8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
8 9 4 10 11 5 2 12 13 6 14 15 7 3 1
*/
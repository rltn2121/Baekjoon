//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//map<string, int> m;
//long long power(int x, int n) {
//	if (n == 0)
//		return 1;
//	if (n == 1)
//		return x;
//	return x * power(x, n - 1);
//}
//long long convert_str_to_ll(string str) {
//	long long ret = 0;
//	if (str[0] == '-') {
//		for (int i = 1; i < str.length(); i++)
//			ret += ((int)str[i] - 48) * power(10, str.length() - 1 - i);
//		return -ret;
//	}
//	else
//	{
//		for (int i = 0; i < str.length(); i++)
//			ret += ((int)str[i] - 48) * power(10, str.length() - 1 - i);
//		return ret;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string str;
//		cin >> str;
//		if (m.find(str) != m.end())
//			m[str]++;
//		else
//			m.insert({ str, 1 });
//	}
//	int max = -1;
//	long long ans;
//	for (auto it : m) {
//		if (it.second > max) {
//			ans = convert_str_to_ll(it.first);
//			max = it.second;
//		}
//		else if (it.second == max) {
//			long long b = convert_str_to_ll(it.first);
//			ans = (ans < b ? ans : b);
//		}
//	}
//	cout << ans;
//}
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll l;
		cin >> l;
		arr[i] = l;
	}
	sort(arr, arr + n);

	int maxLen = -1;
	ll maxVal = 0;
	int length = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1]) 
			length++;
		
		else {
			if (length > maxLen) {
				maxLen = length;
				maxVal = arr[i];
			}
			length = 1;
		}
	}
	if (n == 1)
		cout << arr[0] << endl;
	else
		cout << maxVal << endl;
}
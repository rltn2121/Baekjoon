#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 5; i <= n; i++) {
		int t = i;
		while (t % 5 == 0) {
			cnt++;
			t /= 5;
		}
	}
	cout << cnt << '\n';
}
/*// ex. 33! -> 5,10,15,20,25,30
#include <iostream>
using namespace std;
int main(){
	int n=0, sum=0;
	cin >> n;
	while (n > 0) {
		n /= 5;
		sum += n;
	}
	cout << sum;
}*/
/*#include <stdio.h>
int main() {
	int n, cnt = 0;
	scanf_s("%d", &n);
	for (int i = 5; i < n; i++)	{
		if (n/=5)
			cnt += n;
	}
	printf("%d", cnt);
}*/
#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << '\n';
    return 0;
}

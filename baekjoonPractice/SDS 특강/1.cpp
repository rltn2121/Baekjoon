//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#define rep(i,n) for(int i=0;i<n;i++)
//using namespace std;
//int t, n, arr[8];
//int back() {
//    return arr[0] + arr[1] * 2;
//}
//
//int func(int n) {
//    if (n == 1)
//        return arr[0];
//    else if (n == 2)
//        return arr[1];
//    else if (n == 3)
//        return arr[0] + arr[1] + arr[2];
//    else
//        return back() + arr[n - 1] + func(n - 2);
//}
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cin >> t;
//    rep(j, t) {
//        memset(arr, 0, sizeof(arr));
//        cin >> n;
//        rep(i, n)
//            cin >> arr[i];
//        sort(arr, arr + n);
//        cout << '#' << j + 1 << ' ' << func(n) << '\n';
//    }
//}
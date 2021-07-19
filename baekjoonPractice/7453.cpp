#include <iostream>
#include <algorithm>
#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long
using namespace std;
ll n, arr[4000][4], sum1[4000 * 4000], sum2[4000 * 4000], ans, cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, n) {
        rep(j, 4)
            cin >> arr[i][j];
    }

    ll idx = 0;
    rep(i, n) {
        rep(j, n) {
            sum1[idx] = arr[i][0] + arr[j][1];
            sum2[idx++] = arr[i][2] + arr[j][3];
        }
    }
    sort(sum1, sum1 + idx);
    sort(sum2, sum2 + idx);

    ll l = 0, r = idx - 1;

    //while (l < idx && r >= 0) {
    //    int temp = sum1[l] + sum2[r];

    //    // ���� 0
    //    if (temp == 0) {
    //        if (l > 0 && sum1[l] == sum1[l - 1]) {
    //            ans += cnt;
    //            l++;
    //        }
    //            
    //        else {
    //            cnt = 1;
    //            while (r >0 && sum2[r] == sum2[r - 1]) {
    //                cnt++;
    //                r--;
    //            }
    //            ans += cnt;
    //            l++;
    //        }
    //    }

    //    // ���� 0���� ŭ
    //    else if (temp > 0) {
    //        if (r == 0)         // sum2[]�� �����Ͱ� ���� ���� �����ߴٸ� 
    //            l++;            //  -> sum1[]�� �����͸� ���������� �̵�
    //        else
    //            r--;            // sum2[]�� �����͸� �������� �̵�
    //    }

    //    // ���� 0���� ����
    //    else if (temp < 0) {
    //        if (l == idx - 1)   // sum1[]�� �����Ͱ� ������ ���� �����ߴٸ�
    //            r--;            //  -> sum2[]�� �����͸� �������� �̵�

    //        else
    //            l++;            // sum1[]�� �����͸� ���������� �̵�
    //    }
    //}

    while (l < idx) {
        int temp = sum1[l] + sum2[r];


        if (l > 0 && sum1[l] == sum1[l - 1])
            ans += cnt;

        else {
            while (r >= 0 && temp > 0) {
                r--;
                temp = sum1[l] + sum2[r];
            }

            cnt = 0;
            while (r >= 0 && temp == 0) {
                cnt++;
                r--;
                temp = sum1[l] + sum2[r];
            }
            ans += cnt;
        }

        l++;
    }
    cout << ans;
}
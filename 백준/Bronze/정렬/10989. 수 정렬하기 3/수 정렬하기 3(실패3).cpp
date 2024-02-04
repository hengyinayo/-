/*
접근 방법:
- 수는 10'000까지라고 한다.
- 계수 정렬을 사용.

문졔:
- 시간 초과

원인:
- n 은 10'000'000
- 최약의 경우 10'000이라는 수가 10'000'000개라고 하면, 1'000 *  10'000'000 = 10억
*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j); i>=(int)(k);i--)
#define coutn cout << "\n"
using namespace std;

#define MAX_M 10'000
int arr[MAX_M+1];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp;
    cin >> n;
    For(i,1,n) {
        cin >> temp;
        arr[temp]++;
    }

    For(i,1,MAX_M) {
        For(j,1,arr[i]) {
            cout << i << "\n";
        }
    }
}
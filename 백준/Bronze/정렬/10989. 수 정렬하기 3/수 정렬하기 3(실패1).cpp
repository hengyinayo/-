/*
접근 방식:
- array를 정렬

문제:
- 메모리 초과
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

#define MAX_N 10'000'000

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    int temp;
    For(i,0,n-1) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    For(i,0,n-1) {
        cout << arr[i] << "\n";
    }

    return 0;
}
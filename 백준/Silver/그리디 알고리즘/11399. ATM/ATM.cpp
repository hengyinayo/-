/*
접근 방법:
- sort() 내장된 함수를 사용
- sort()의 3번째 parameter에 내가 지정한 함수를 넣어줌.
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

#define MAX_N 1000

int arr[MAX_N+1];
int n;

int main() {
    cin >> n;
    For(i,1,n) {
        cin >> arr[i];
    }

    sort(arr, arr+n+1);

    int sum=0;
    int prev=0;
    For(i,1,n) {
        prev += arr[i];
        sum += prev;
    }
    cout << sum;
    return 0;
}
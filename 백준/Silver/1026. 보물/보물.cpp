/*
접근 방법:
- arrA랑 arrB라는 배열을 만들어줌.
- 하나는 내림차순, 하나는 오른차순으로 정렬.
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

#define MAX_N 50

int arrA[MAX_N+1];
int arrB[MAX_N+1];
int n;

int main() {
    cin >> n;
    For(i,1,n) {
        cin >> arrA[i];
    }
    For(i,1,n) {
        cin >> arrB[i];
    }

    sort(arrA+1, arrA+n+1);
    sort(arrB+1, arrB+n+1, greater<>());

    int sum=0;
    For(i,1,n) {
        sum += (arrA[i] * arrB[i]);
    }

    cout << sum;

    return 0;
}
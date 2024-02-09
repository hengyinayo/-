/*
접근 방법:
- 정렬:
- 각 M개의 숫자를 for loop으로 iterate하면서 binary_search()함수를 사용하여 이진 탐색을 진행.
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

#define MAX_N 500'000
#define MAX_M 500'000

int n, m;
int arrN[MAX_N+1];
int arrM[MAX_M+1];

int main() {
    cin >> n;
    For(i,1,n) {
        cin >> arrN[i];
    }
    cin >> m;
    For(i,1,m) {
        cin >> arrM[i];
    } 

    sort(arrN+1, arrN+n+1);

    bool isExist;
    For(i,1,m) {
        isExist = binary_search(arrN+1, arrN+1+n, arrM[i]);
        if (isExist) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}

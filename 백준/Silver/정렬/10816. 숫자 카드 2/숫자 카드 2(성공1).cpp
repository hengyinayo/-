/*
접근 방법:
- 정렬:
- 각 M개의 숫자를 for loop으로 iterate하면서 binary_search()함수를 사용하여 이진 탐색을 진행.
- lower_bound과 upper_bound함수를 이용해서, lower_bound와 upper_bound의 차이를 계산 -> 이것이 바로 타겟 넘버의 개수이다.
- 시간초과는 cin.tie(NULL)로 해결했다.
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
    cin.tie(NULL);
    cin >> n;
    For(i,1,n) {
        cin >> arrN[i];
    }
    sort(arrN+1, arrN+1+n);

    int cnt;
    int lowNum, upNum;
    cin >> m;
    For(i,1,m) {
        cin >> arrM[i];
        cnt = 0;
        lowNum = lower_bound(arrN+1, arrN+1+n, arrM[i]) - (arrN+1);
        upNum = upper_bound(arrN+1, arrN+1+n, arrM[i]) - (arrN+1);
        cout << upNum - lowNum << " ";
    }
    return 0;
}
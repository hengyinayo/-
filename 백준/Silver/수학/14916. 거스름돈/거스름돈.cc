/*
접근 방법:
- 2를 계속 빼주면서 5로 나눠지면 5로 나눠줌
- 이 개수들을 세줌

문제:
- 2원 보다 적었을 때, while loop에 진입하게 된다,
- 왜냐하면 1 % 5 = 1인데 이것은 0이 아니기 때문이다.
- 따라서, while loop 조건에 n - 2원이 항상 0보다 커야한다는 조건을 걸어준다.
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

#define MAX_N 100'000

int n, twoWon = 2, fiveWon = 5, cnt = 0;

int main() {
    cin >> n;
    while (n % fiveWon != 0 && n - twoWon >= 0) {
        n -= twoWon;
        cnt++;
    }
    if (n % fiveWon == 0) cnt += (n / fiveWon);
    else cnt = -1;
    cout << cnt;
    return 0;
}
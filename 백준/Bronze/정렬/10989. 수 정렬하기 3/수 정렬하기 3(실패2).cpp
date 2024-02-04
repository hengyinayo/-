/*
접근 방식:
- vector를 정렬

문제:
- 메모리 초과

원인:
- int 배열은 4byte.
- MAX_N은 10'000'000, 즉 1000만이니깐 4 * 1000만 = 4000만 = 40MB이다
- 문제 조건의 8MB를 초과한다.
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

int n;
vector<int> vec;

int main() {
    cin >> n;
    int temp;
    For(i,0,n-1) {
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    For(i,0,n-1) {
        cout << vec[i] << "\n";
    }

    return 0;
}
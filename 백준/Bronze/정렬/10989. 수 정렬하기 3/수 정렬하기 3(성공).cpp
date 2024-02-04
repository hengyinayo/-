/*
접근 방법:
- 계수 정렬
- ios::sync_with_stdio(false); // C입출력 방식 사용제한
- cin.tie(NULL) // 앞에서 cout으로 출력을 한다면 출력전에 입력부터 진행
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
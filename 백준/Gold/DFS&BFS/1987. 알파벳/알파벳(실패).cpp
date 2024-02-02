/*
접근 방식:
- dfs

반례:
2 4
CALB
ADCB


이 반례처럼, 나의 cnt는 모든 visited한 격자의 수를 반환한다.
위의 코드는 C -> A -> L -> B  + D가 포함된다.
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

#define MAX_N 20
#define MAX_M 20

char arr[MAX_N+1][MAX_M+1];
int n, m, cnt=0;
bool visited[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int nr, int nc) {
    return 1 <= nr && nr <= n && 1 <= nc && nc <= m;
}

void dfs(int r, int c) {
    int nr, nc;
    For(i,0,3) {
        nr = r + dx[i];
        nc = c + dy[i];
        if (inRange(nr, nc) && !visited[arr[nr][nc] - 'A']) {
            cnt++;
            visited[arr[nr][nc] - 'A'] = true;
            dfs(nr, nc);
        }
    }
}

int main() {
    cin >> n >> m;
    For(i,1,n) {
        For(j,1,m) {
            cin >> arr[i][j];
        }
    }

    visited[arr[1][1] - 'A'] = true;
    cnt++;
    dfs(1,1);
    cout << cnt;

    return 0;
}

/*
- visited배열은 필요없다.
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
int n, m,cnt=1;
bool alphabet[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int nr, int nc) {
    return 1 <= nr && nr <= n && 1 <= nc && nc <= m;
}

void dfs(int r, int c, int curCnt) {

    int nr, nc;
    alphabet[arr[r][c] - 'A'] = true;
    cnt = max(cnt, curCnt);
    For(i,0,3) {
        nr = r + dx[i];
        nc = c + dy[i];
        if(inRange(nr, nc) && !alphabet[arr[nr][nc] - 'A']) {
            dfs(nr, nc, curCnt+1);
            alphabet[arr[nr][nc] - 'A'] = false;
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
    dfs(1, 1, 1);

    cout << cnt;

    return 0;
}
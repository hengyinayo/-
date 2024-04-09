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
#define MAX_M 50

int n, m;
int arr[MAX_N+1][MAX_M+1];
int r, c, d, cnt=0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int nr, int nc) {
    return 1 <= nr && nr <= n && 1 <= nc && nc <= m;
}

bool cleaningAvailable(int r, int c) {
    int nxtR, nxtC;
    For(dir,0,3) {
        nxtR = r + dx[dir];
        nxtC = c + dy[dir];
        if (inRange(nxtR, nxtC) && arr[nxtR][nxtC] == 0) {
            return true;
        }
    }
    return false;
}

bool backAvailable(int nr, int nc) {
    return inRange(nr, nc) && arr[nr][nc] != 1;
}

void getInput() {
    cin >> n >> m;
    cin >> r >> c >> d;
    r+=1;
    c+=1;
    For(i,1,n) {
        For(j,1,m) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    getInput();

    int nr, nc;
    while(true) {
        // 1. 현재 칸 청소 X, 현재 칸 청소
        if (arr[r][c] == 0) {
            arr[r][c] = 2;
            cnt++;
        }

        // 2. 주변 다 1 or 2, 후진 가능 -> 후진 후 1번, 후진 불가능 -> 멈춤
        if (!cleaningAvailable(r, c)) {
            nr = r + dx[(d+2)%4];
            nc = c + dy[(d+2)%4];
            if (!backAvailable(nr, nc)) {
                break;
            }
            r = nr;
            c = nc;
        }
        // 3. 주변에 0이 있음, 반시계, 앞쪽이 0 -> 전진, 1번
        else {
            d += 3;
            nr = r + dx[d%4];
            nc = c + dy[d%4];
            if (inRange(nr, nc) && arr[nr][nc] == 0) {
                r = nr;
                c = nc;
            }
        }
    }

    cout << cnt;
    return 0;
}
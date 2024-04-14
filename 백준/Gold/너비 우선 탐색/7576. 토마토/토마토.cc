#include <bits/stdc++.h>

#define pii pair<int, int>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j); i>=(int)(k);i--)
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define coutn cout << "\n"

using namespace std;

#define MAX_N 1000
#define MAX_M 1000

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, day;
int arr[MAX_N+1][MAX_M+1];
bool visited[MAX_N+1][MAX_M+1];
queue<tuple<int, int, int>> q;

bool inRange(int nr, int nc) {
    return 1 <= nr && nr <= n && 1 <= nc && nc <= m;
}

bool canGo(int nr, int nc) {
    return inRange(nr, nc) && arr[nr][nc] == 0;
}

void bfs() {
    int r, c, nr, nc, cnt;
    while(!q.empty()) {
        tie(r, c, cnt) = q.front(); q.pop();
        day = max(day, cnt);
        For(i,0,3) {
            nr = r + dx[i];
            nc = c + dy[i];
            if (!canGo(nr, nc)) continue;
            q.push(make_tuple(nr, nc, cnt+1));
            arr[nr][nc] = 1;
        }
    }
    return;
}

int main() {
    cin >> m >> n;
    For(i,1,n) {
        For(j,1,m) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_tuple(i,j,0));
            }
        }
    }

    bfs();

    For(i,1,n) {
        For(j,1,m) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day;
    return 0;
}
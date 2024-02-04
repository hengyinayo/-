#include <bits/stdc++.h>
#define pii pair<int, int>
#define For(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define debug4 puts("--@444%--")
#define coutn cout << "\n"

using namespace std;

#define MAX_N 50
#define MAX_M 50

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int n, m, c, t;
queue<pii> q;

bool inRange(int nx, int ny) {
    return 0 <= nx && nx <= n-1 && 0 <= ny && ny <= m-1;
}

bool canGo(int nx, int ny) {
    return inRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1;
}

void bfs() {
    int x, y, nx, ny;
    while(!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        For(i,0,3) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (canGo(nx, ny)) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void reset() {
    For(i,0,n-1) {
        For(j,0,m-1) {
            visited[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

int main() {
    cin >> t;
    int x, y;
    int cnt;
    For(i,1,t) {
        cin >> m >> n >> c;

        reset();
        For(j,1,c) {
            cin >> y >> x;
            arr[x][y] = 1;
        }
        
        cnt = 0;
        For(j,0,n-1) {
            For(k,0,m-1) {
                if (visited[j][k] || arr[j][k] == 0) continue;
                q.push(make_pair(j, k));
                visited[j][k] = true;
                bfs();
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}

#include <iostream>
using namespace std;

#define MAX_N 100

char arr[MAX_N+1][MAX_N+1];
char arrBlind[MAX_N+1][MAX_N+1];
bool visitedNotBlind[MAX_N+1][MAX_N+1];
bool visitedBlind[MAX_N+1][MAX_N+1];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, cntNotBlind = 0, cntBlind = 0;
char cur_rgb;

bool inRange(int nr, int nc) {
    return nr >= 1 && nr <= n && nc >= 1 && nc <= n;
}

void dfs(int r, int c) {
    int nr, nc;
    for(int i = 0; i < 4; i++) {
        nr = r + dx[i];
        nc = c + dy[i];
        if(inRange(nr, nc) && !visitedNotBlind[nr][nc] && arr[nr][nc] == cur_rgb) {
            visitedNotBlind[nr][nc] = true;
            dfs(nr, nc);
        }
    }
}

void dfs_blind(int r, int c) {
    int nr, nc;
    for(int i = 0; i < 4; i++) {
        nr = r + dx[i];
        nc = c + dy[i];
        if(inRange(nr, nc) && !visitedBlind[nr][nc] && arrBlind[nr][nc] == cur_rgb) {
            visitedBlind[nr][nc] = true;
            dfs_blind(nr, nc);
        }
    }
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'G') {
                arrBlind[i][j] = 'R';
            } else {
                arrBlind[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visitedNotBlind[i][j]) {
                visitedNotBlind[i][j] = true;
                cur_rgb = arr[i][j];
                dfs(i, j);
                cntNotBlind++;
            }
            if (!visitedBlind[i][j]) {
                visitedBlind[i][j] = true;
                cur_rgb = arrBlind[i][j];
                dfs_blind(i, j);
                cntBlind++;
            }

        }
    }

    cout << cntNotBlind << " " << cntBlind;

}
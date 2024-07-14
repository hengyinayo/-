/*
접근 방법:
3가지의 경우의 수가 있음 -> -1, +1, *2
시작 숫자에서부터 이 3가지의 경우를 큐에다가 저장 (숫자, 카운트) 형태로,
만약 이미 도달했었던 숫자면 (중복) 패스.

문제:
해당 숫자에 도달하면, 그게 최적이든 아니든 바로 그 카운트가 반환됨.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N_K 100'000

bool check[MAX_N_K+1];
queue <pair<int, int>> q;
int n, k;

int main() {
    cin >> n >> k;
    int cur = n;
    int cnt;
    q.push({n, 0});
    check[n] = true;

    while(!q.empty()) {
        cur = q.front().first;
        cnt = q.front().second;
        q.pop();

        cout << "current: " << cur << "  count: " << cnt << "\n";

        if (cur == k) {
            cout << cnt;
            break;
        }
        if (cur * 2 <= MAX_N_K && check[cur*2] != true) {
            check[cur*2] = true;
            q.push({cur*2, cnt});
        }
        if (cur + 1 <= MAX_N_K && check[cur+1] != true) {
            check[cur+1] = true;
            q.push({cur+1, cnt+1});
        }
        if ( cur - 1 >= 0 && check[cur-1] != true) {
            check[cur-1] = true;
            q.push({cur-1, cnt+1});
        }
    }
    return 0;
}
/*
접근 방법:
bfs를 활용, visited 배열은 최소의 cnt를 저장

start가 target보다 클 경우, 한 가지의 경우 (-1) 밖에 없으므로 그냥 빼줌
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX_N_K 100'000

queue <pair<int, int>> q;
int visited[MAX_N_K+1];
int start, target;

bool inRange(int x1) {
    return x1 >= 0 && x1 <= MAX_N_K;
}

void bfs() {
    int number;
    int cnt;
    while(!q.empty()) {
        number = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (inRange(number-1) && (visited[number-1] == -1 || cnt+1 < visited[number-1])) {
            q.push({number-1, cnt+1});
            visited[number-1] = cnt+1;
        }
        if (inRange(number+1) && (visited[number+1] == -1 || cnt+1 < visited[number+1])) {
            q.push({number+1, cnt+1});
            visited[number+1] = cnt +1;
        }
        if (number != 0 && inRange(number*2) && (visited[number*2] == -1 || cnt < visited[number*2])) {
            q.push({number*2, cnt});
            visited[number*2] = cnt;
        }
    }
}

int main() {
    cin >> start >> target;

    for(int i=0; i <= MAX_N_K; i++) {
        visited[i] = -1;
    }

    if (start >= target) {
        cout << start - target;
    } else {
        q.push({start, 0});
        bfs();
        cout << visited[target];
    }
    return 0;
}
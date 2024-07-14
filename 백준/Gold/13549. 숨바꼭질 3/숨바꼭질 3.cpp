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


// 다른 답안
/*
priority queue를 활용해서 -> 빠지는 건 최소 혹은 최대 숫자가 빠지게
- Max Heap, Min Heap
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_N_K 100'000

bool visited[MAX_N_K+1];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int start, target;

int bfs() {
    while(!pq.empty()) {
        int cnt = pq.top().first;
        int num = pq.top().second;
        pq.pop();
        
        if (num == target) return cnt;

        if (num * 2 <= MAX_N_K && !visited[num * 2]){
            pq.push({cnt, num*2});
            visited[num * 2] = true;
        }

        if (num + 1 <= MAX_N_K && !visited[num + 1]) {
            pq.push({cnt+1, num+1});
            visited[num+1] = true;
        }

        if (num - 1 >= 0 && !visited[num-1]) {
            pq.push({cnt+1, num-1});
            visited[num-1] = true;
        }
    }
    return -1;
}

int main() {
    cin >> start >> target;

    pq.push({0, start});

    cout << bfs();

    return 0;
}
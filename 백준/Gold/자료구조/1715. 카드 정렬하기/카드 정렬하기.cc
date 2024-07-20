/*
접근 방법:
정렬하고 최소부터 합치면 됨.

문제:
생각보다 조금 까다로운 문제였다.
정렬을 해서 항상 최소의 "장수가 적은 뭉치 끼리" 차근히 더한다고 해도,
계속 더 해줄 수록 그 "뭉치의 장수는 계속 커지게 될것".
즉, 현재 존재하는 카드 묶음 중에서, 가장 적은 2개의 묶음을 우선적으로 계산해야한다.

따라서, priority queue를 쓰면 손쉽게 계산할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 100'000
int n, cnt;
priority_queue<int> pq;

int main() {
    cin >> n;

    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        pq.push(-x);
    }

    // 엣지 케이스
    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }
    
    int a, b;
    while(pq.size() != 1) {
        a = -pq.top(); pq.pop();
        b = -pq.top(); pq.pop();
        cnt += a + b;
        pq.push(-(a+b));
    }
    cout << cnt;
    return 0;
    
}
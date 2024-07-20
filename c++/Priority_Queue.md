Default: 최대 힙

```python
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;

    // 요소 추가
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // 요소 제거 및 접근
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // 큐의 맨 앞 요소 (최대 힙에서는 가장 큰 값)
        pq.pop(); // 요소 제거
    }

    return 0;
}

출력:
30 20 10 5
```

최소 힙

```python
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // std::greater 사용

int main() {
    // 최소 힙을 위해 greater<int> 사용
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // 요소 추가
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // 요소 제거 및 접근
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // 큐의 맨 앞 요소 (최소 힙에서는 가장 작은 값)
        pq.pop(); // 요소 제거
    }

    return 0;
}

출력:
5 10 20 30
```

최소 힙: -를 사용

```python
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> maxHeap;

    // 값의 부호를 반전시켜 삽입 (최소 힙처럼 동작)
    maxHeap.push(-10);
    maxHeap.push(-30);
    maxHeap.push(-20);
    maxHeap.push(-5);

    // 요소 제거 및 접근 (최소부터)
    while (!maxHeap.empty()) {
        std::cout << -maxHeap.top() << " "; // 큐의 맨 앞 요소 (부호를 다시 반전)
        maxHeap.pop(); // 요소 제거
    }

    return 0;
}

출력:
5 10 20 30
```
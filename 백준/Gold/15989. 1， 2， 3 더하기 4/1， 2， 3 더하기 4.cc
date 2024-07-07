/*
7일 때, 1 + 1 + 1 + ... + 1 -> 1가지;
그리고 2와 1로만 구성된 7 // 2 -> 3가지;
그리고 3과 1로만 구성된 7 // 3 -> 2가지;

3과 2로의 조합으로 된 것을 구해야되는데, 3을 하나 쓴다는 가정 -> 7-3 = 4
4 // 2 -> 2 가지;
2일 때 stop;

10과도 위와 같은 방식으로, 3과 2로의 조합에서는 
10 - 3 = 7:
- 7 // 2 -> 3가지

7 - 3 = 4;
- 4 // 2 -> 2가지

이런식으로

마지막으로는 모든 조합의 수를 더해줌
*/
#include <iostream>
using namespace std;

int n;

void combination(int num) {
    int cnt = 0;
    cnt += num / 2;
    cnt += num / 3;
    while (num-3 >= 2) {
        num -= 3;
        cnt += num / 2;
    }
    cout << cnt+1 << "\n";
}

int main() {
    cin >> n;
    int num;
    for (int i=0; i < n; i++) {
        cin >> num;
        combination(num);
    }
    return 0;
}
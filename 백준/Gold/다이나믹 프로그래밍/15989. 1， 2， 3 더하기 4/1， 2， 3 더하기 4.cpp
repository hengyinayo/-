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

/*
다이나믹 프로그래밍:

접근 방법:
2차원 배열,
i에 대해서 1로 만드는 경우의 수 -> dp[i][1]
i에 대해서 2로 만드는 경우의 수 -> dp[i][2]
i에 대해서 3으로 만드는 경우의 수 -> dp[i][3]

각 i에 대해, dp[i][1]은 i-1을 1로 끝내는 경우의 수와 같음
dp[i][2]은 i-2를 1또는 2로 끝내는 경우의 수의 합과 같음
dp[i][3]은 i-3를 1, 2, 3으로 끝내는 경우의 수의 합과 같음

#include <iostream>
using namespace std;

#define MAX_N 10'000

int n;
int dp[MAX_N+1][4];

int main() {
    cin >> n;
    
    // 초기화
    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for (int i = 4; i <= MAX_N; i++) {
        dp[i][1] = dp[i-1][1]; // i 를 1로 만든느 경우
        dp[i][2] = dp[i-2][1] + dp[i-2][2]; // i를 1, 2로 만드는 경우
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3]; // i를 1, 2, 3으로 만드는 경우
    }

    int num;
    while (n--) {
        cin >> num;
        cout << dp[num][1] + dp[num][2] + dp[num][3] << "\n";
    }

    return 0;
}
*/

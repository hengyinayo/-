/*
접근 방법:
- %연산을 이용해서 몇 칸을 비워야 하는지 계산하고 카운트한다.

문졔: 시간초과
*/

#include <iostream>
using namespace std;

#define MAX 50'000

int H, W, N, M;

int main() {
    int cnt=0;
    cin >> H >> W >> N >> M;
    // 세로 N칸, 가로 M칸 비우기
    for(int i=0; i<H; i++){
        if (i % (N+1) == 0) {
            for (int j=0; j<W; j++) {
                if (j % (M+1) == 0) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}

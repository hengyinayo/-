/*
접근 방법:
- 각 행과 열에 몇 명의 참가자들이 들어갈 수 있는지 구하고, 곱해주면 됨.
*/

#include <iostream>
using namespace std;

#define MAX 50'000

int H, W, N, M;

int main() {
    cin >> H >> W >> N >> M;
    int row, col;
    if (W % (M+1) == 0) {
        row = W / (M+1);
    } else {
        row = W / (M+1) + 1;
    }

    if (H % (N+1) == 0) {
        col = H / (N+1);
    } else {
        col = H / (N+1) + 1;
    }
    
    cout << row * col;
    return 0;
}

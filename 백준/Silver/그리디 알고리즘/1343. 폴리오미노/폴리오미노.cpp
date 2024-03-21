/*
접근 방법:
1. 입력 받을 보드판과 최종 결과값을 선언한다(string).
2. '.'이 나올 때까지 순회한다.
3. 한 글자씩 검사해, 글자가 'X'이면 카운트를 센다.
4. '.'이 나왔을 때 카운트가 홀수이면 반복문을 빠져나와 -1을 출력한다.
5. '.'이 나왔을 때 카운트가 짝수이면 결과값에 '.' 추가.
6. 카운트가 2가 되면 결과값에 "BB" 추가.
7. 카운트가 4가 되면 결과값에 "AAAA" 추가.
8. 최종 결과 출력
*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j); i>=(int)(k);i--)
#define coutn cout << "\n"
using namespace std;

#define MAX_N 50

int cnt = 0;
string board, output = "";

int main() {
    cin >> board;
    For(i, 0, board.length()-1) {
        if (board[i] == 'X') cnt++;

        if (board[i] == '.') {
            output += '.';

            if (cnt % 2 != 0) break;
            else cnt = 0;
        }

        if (cnt == 2 && board[i+1] != 'X') {
            output += "BB";
            cnt = 0;
        }

        if (cnt == 4) {
            output +=  "AAAA";
            cnt = 0;
        }
    }

    if (cnt % 2 == 1) cout << -1;
    else cout << output;

    return 0;
}
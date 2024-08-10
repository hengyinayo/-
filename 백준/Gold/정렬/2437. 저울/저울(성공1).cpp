/*
접근 방식:
처음엔
- 홀홀 -> 짝
- 짝짝 -> 짝
이런 식으로 접근을 하였다.

문제:
홀홀 + 짝짝 -> 짝, 즉, 홀은 항상 쌍으로 이루어져야 하며, 고려해야할 부분이 너무 많고, 시간 제한안에 연산을 끝내지 못할 거 같다.

해결법:
- 측정 가능한 부분이 끊기지 않아야 한다.

            |------------------| (추가 측정 가능 구간)
1  2  3  4  5  6  7  8  9  10  11  12
|-----------| (기존 측정 가능 구간)
|-------------------------------| (새로운 측정 가능 구간)

예를 들어, 
1~7의 구간을 저울로 측정 가능하다고 할때, 
4kg의 저울이 추가되면 [1+4, 7+4], 즉 [1, 11]까지의 구간을 측정 가능하게 된다.
(1+4 = 5는 1~7의 범위 안에 있고, 1+4=5 ~ 7+4=11까지의 구간을 측정 가능하기 때문)

만약,
11kg의 저울이 추가되면, 
[1+11, 7+11], 즉 1~7, 12 ~18로서 8~10까지의 구간을 측정하지 못한다.
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

#define MAX_N 1'000

int arr[MAX_N+1];
int even[MAX_N+1];
int odd[MAX_N+1];
int n;

int main() {
    cin >> n;
    For(i,1,n) {
        cin >> arr[i];
    }

    // 정렬
    sort(arr, arr+(n+1));

    if (arr[1] > 1) {
        cout << 1;
        return 0;
    }
    if (arr[2] > 2) {
        cout << 2;
        return 0;
    }

    int lowerBound = arr[1];
    int upperBound = lowerBound + arr[2];
    int addWeight;

    For(i,3,n) {
        addWeight = arr[i];
        if (addWeight == upperBound + 1) {
            upperBound += addWeight; 
        }
        else if (lowerBound + addWeight <= upperBound + 1) {
            upperBound += addWeight;
        }
        else {
            break;
        }
    }

    cout << upperBound + 1;

    return 0;
}
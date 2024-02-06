/*
접근 방법:
- 정렬
- start(-0.5)와 end(+0.5)를 설정해주고, 테이프의 길이(start + l)도 설정해준다.
- 만약 arr에 있는 요소가 테이프의 길이 내에 있으면 continue
- 만약 arr에 있는 요소가 테이프의 길이 밖에 있으면 테이프의 길이를 다시 설정해줌, 그리고 cnt++
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

#define MAX_N 1000

int n, l;
int arr[MAX_N+1];

int main() {
    cin >> n >> l;

    For(i,1,n) {
        cin >> arr[i];
    }

    sort(arr+1, arr+1+n);

    float start, end, length=-1;
    int cnt=0;
    For(i,1,n) {
        if (arr[i] < length) {
            continue;
        }
        start = arr[i] - 0.5;
        end = arr[i] + 0.5;
        length = start + l;
        cnt++;
    }

    cout << cnt;

}
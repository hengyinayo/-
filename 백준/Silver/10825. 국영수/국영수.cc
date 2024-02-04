/*
접근 방법:
- 계수 정렬
- ios::sync_with_stdio(false); // C입출력 방식 사용제한
- cin.tie(NULL) // 앞에서 cout으로 출력을 한다면 출력전에 입력부터 진행
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

#define MAX_N 100'000

int n;
vector<tuple<string, int, int, int>> student;

static bool Cmp(tuple<string, int, int, int> &v1, tuple<string, int, int, int> &v2) {
    return (get<1>(v1) > get<1>(v2)) || 
           (get<1>(v1) == get<1>(v2) && get<2>(v1) < get<2>(v2)) ||
           (get<1>(v1) == get<1>(v2) && get<2>(v1) == get<2>(v2) && get<3>(v1) > get<3>(v2)) ||
           (get<1>(v1) == get<1>(v2) && get<2>(v1) == get<2>(v2) && get<3>(v1) == get<3>(v2) && get<0>(v1) < get<0>(v2));
}

int main() {
    cin >> n;
    string name;
    int korean, english, math;
    For(i,1,n) {
        cin >> name >> korean >> english >> math;
        student.push_back({name, korean, english, math});
    }

    sort(student.begin(), student.end(), Cmp);

    For(i,0,n-1) {
        cout << get<0>(student[i]) << "\n";
    }
}
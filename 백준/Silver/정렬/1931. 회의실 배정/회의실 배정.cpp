#include <bits/stdc++.h>

#define pii pair<int, int>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j); i>=(int)(k);i--)
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define coutn cout << "\n"

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
vector<pii> vec;

int main() {
    cin >> n;

    int x1, x2;
    For(i,1,n) {
        cin >> x1 >> x2;
        vec.push_back(make_pair(x2, x1));
    }

    sort(vec.begin(), vec.end());

    int cnt = 1, end = vec[0].first;
    For(i,1,vec.size()-1) {
        if (vec[i].second >= end) {
            cnt++;
            end = vec[i].first;
        }
    }

    cout << cnt;

    return 0;
}
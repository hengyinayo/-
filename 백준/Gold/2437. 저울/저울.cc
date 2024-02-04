#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j); i>=(int)(k);i--)
#define coutn cout << "\n"
using namespace std;

vector<int> v;
int n;
int sum=0;

int main() {
    cin >> n;
    
    For(i,0,n-1) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    For(i,0,n-1) {
        if (v[i] > sum + 1) break;
        sum += v[i];
    }

    cout << sum + 1;

    return 0;
}
#include <bits/stdc++.h>
#define For(i,j,k) for(int i=(int)(j);i<(int)(k);i++)
#define coutn cout << '\n'
#define ll long long
#define all(v) (v).begin, (v).end()
#define debug1 puts("--@111%--")
#define debug2 puts("--@222%--")
using namespace std;

int main() {
    string s;
    cin >> s;
    string arr[s.length()];

    For(i,0,s.length()) {
        arr[i] = s.substr(i, -1);
    }

    sort(arr, arr + s.length());

    For(i,0,s.length()) {
        cout << arr[i];
        coutn;
    }
}
/*
if-else 활용
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, big, small1, small2;
    while(cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) return 0;
        int big = a > b ? (a > c ? a : c) : (b > c ? b : c);
        
        if (big == a) {
            small1 = b > c ? c : b;
            small2 = b > c ? b : c;
        } else if (big == b) {
            small1 = a > c ? c : a;
            small2 = a > c ? a : c;
        } else if (big == c) {
            small1 = a > b ? b : a;
            small2 = a > b ? a : b;
        }

        if (a == b && b == c) cout << "Equilateral\n"; 
        else if (big >= (small1 + small2)) cout << "Invalid\n";
        else if (a == b || a == c || b == c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}
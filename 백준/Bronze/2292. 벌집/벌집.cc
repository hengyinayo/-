/*
접근 방법: 1 -> 6 -> 12 -> 18, 즉 6의 배수만큼의 새로운 방이 늘어남.
따라서, 계속해서 6의 배수만큼 빼주면 됨
*/
#include <iostream>
#include <cmath>
using namespace std;

double n;

int main() {
    cin >> n;
    int i = 0, cnt = 0;
    while (n > 0) {
        if (i == 0) n -= 1; 
        else n -= 6 * i;
        cnt++;
        i++;
    }
    cout << cnt;
    return 0;
}
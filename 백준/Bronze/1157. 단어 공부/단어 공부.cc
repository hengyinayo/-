/*
배열을 이용해서, 해당 알파벳 순서에 개수를 기록하고,
가장 많았던 알파벳을 반환하면 됨
*/

#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 26

int arr[ALPHABET_SIZE+1];
string str;

int main() {
    cin >> str;

    // 배열 초기화
    for (int i=0; i <= ALPHABET_SIZE; i++) {
        arr[i] = 0;
    }

    for(int i=0; i < str.length(); i++) {
        arr[(char)toupper(str[i]) - 'A']++;
    }

    char ch;
    int maxCnt = 0;
    bool duplicate = false;
    for(int i=0; i <= ALPHABET_SIZE; i++) {
        if (arr[i] > maxCnt) {
            maxCnt = arr[i];
            ch = 'A' + i;
            duplicate = false;
        } else if (arr[i] == maxCnt) {
            duplicate = true;
        }
    }

    if (duplicate) cout << "?";
    else cout << ch;
    return 0;
}
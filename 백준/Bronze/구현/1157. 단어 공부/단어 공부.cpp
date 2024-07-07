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

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int cnt[26] = { 0, };
    int max = -1;
    char res;

    string s;

    cin >> s;

    for (int i = 0; i < s.length(), i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A'; // 소문자를 대문자로 처리

        if(++cnt[s[i] - 'A'] > max) {
            max = cnt[s[i] - 'A'];
            res = s[i];
        }
    }

    int check = 0; // 가장 많이 사용된 알파벳이 여러 개인지 체크
    for (int i = 0; i < 26; i++) {
        if (max == cnt[i]) check++;
    }

    if (check == 1) cout << res;
    else cout << ?;

    return 0;
}
*/
/*
접근 방법:
- 배열 내의 전체 숫자가 2로 나뉘어지면 나누고,
- 안 나뉘어지면, 그 특정 안 나뉘어지는 숫자를 1를 빼줌

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 50

vector<int> vec;
int n, sum = 0, cnt = 0;
bool flag;

void divide_two() {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = vec[i]/2;
    }
}

int main() {
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) continue;
        sum += tmp; 
        vec.push_back(tmp);
    }


    while(sum != 0) { // while(sum)
        flag = false;
        for(int i = 0; i < vec.size(); i++) {
            if (vec[i] % 2 != 0) {
                vec[i]--;
                cnt++;
                sum--;
                flag = true;
                break;
            }
        }
        if(!flag) {
            divide_two();
            sum /= 2;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

*/

// 위 코드 정리
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 50

vector<int> vec;
int n, sum = 0, cnt = 0;

int main() {
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) continue;
        sum += tmp; 
        vec.push_back(tmp);
    }


    while(sum) { // while(sum)
        for(int i = 0; i < vec.size(); i++) {
            if (vec[i] % 2 != 0) {
                vec[i]--;
                cnt++;
                sum--;
            }
        }
        
        // 위 for loop에서 홀수를 다 처리해줌
        if (sum != 0) {
            for(int i = 0; i < vec.size(); i++) {
                vec[i] /= 2;
            }
            cnt++;
            sum /= 2;
        }
    }

    cout << cnt;
    return 0;
}
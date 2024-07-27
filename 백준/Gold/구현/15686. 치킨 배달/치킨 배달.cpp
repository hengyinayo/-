/*
접근 방법:
- 각 치킨집으로부터 집들의 치킨 거리를 구함,
- 각 집의 최소의 치킨 거리의 합을 구함
- 배열 2개 사용 1. 원본, 2. 치킨 거리
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_INT 987654321
#define MAX_N 50
#define MAX_M 13

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> dist;
vector<int> choose;
bool visited[MAX_M];

int n, m, sum = MAX_INT;

void back(int cnt, int pre) {
    if (cnt == m) {
        int tmpSum = 0;
        for (int i = 0; i < dist[0].size(); i++) {
            int temp = MAX_INT;
            for (int j = 0; j < choose.size(); j++) {
                temp = min(temp, dist[choose[j]][i]);
            }
            tmpSum += temp;
        }
        sum = min(sum, tmpSum);
    } else {
        for (int cur = pre + 1; cur < dist.size(); cur++) {
            choose.push_back(cur);
            back(cnt + 1, cur);
            choose.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    int x;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1) house.push_back({i, j});
            else if (x == 2) chicken.push_back({i, j});
        }
    }

    int d;
    vector<int> temp;
    for(int i = 0; i < chicken.size(); i++) {
        for(int j = 0; j < house.size(); j++) {
            d = abs(chicken[i].first - house[j].first) + abs(chicken[i].second - house[j].second);
            temp.push_back(d); 
        }
        dist.push_back(temp);
        temp.clear();
    }

    back(0, -1);
    
    cout << sum;

    return 0;

}
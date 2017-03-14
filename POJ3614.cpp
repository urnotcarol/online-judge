#include <iostream>
#include <stdio.h>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int MAX_C = 2500;
const int MAX_L = 2500;
int C;
int L;
pair<int, int> cow[MAX_C + 4];
pair<int, int> lotion[MAX_L + 4];

int main() {
    scanf("%d %d", &C, &L);
    for (int i = 0; i < C; i++) {
        scanf("%d %d", &cow[i].first, &cow[i].second);
    }
    
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 0; i < L; i++) {
        scanf("%d %d", &lotion[i].first, &lotion[i].second);
    }
    sort(cow, cow + C);
    sort(lotion, lotion + L);
    
    int res = 0;
    int cur = 0;
    for (int i = 0; i < L; i++) {
        while (cur < C && cow[cur].first <= lotion[i].first) {
            que.push(cow[cur].second);
            cur++;
        }
        while (!que.empty() && lotion[i].second) {
            int maxSPF = que.top();
            que.pop();
            if (maxSPF >= lotion[i].first) {
                res++;
                lotion[i].second--;
            }
        }
    }
    cout << res;
    return 0;
}

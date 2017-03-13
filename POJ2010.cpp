#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

const int MAX_C = 100000;
int N;
int C;
int F;
pair<int, int> cow[MAX_C + 4];
int lower[MAX_C + 4];
int upper[MAX_C + 4];

int main() {
    scanf("%d %d %d", &N, &C, &F);
    for (int i = 0; i < C; i++) {
        scanf("%d %d", &cow[i].first, &cow[i].second);
    }
    
    sort(cow, cow + C);
    int first = N / 2;
    int last = C - first - 1;
    
    priority_queue<int> que;
    int total = 0;
    for (int i = 0; i < first; i++) {
        total += cow[i].second;
        que.push(cow[i].second);        
    }
    
    for (int i = first; i <= last; i++) {
        lower[i] = total;
        int aid = cow[i].second;
        int top = que.top();
        if (aid < top) {
            que.pop();
            que.push(aid);
            total = total - top + aid;
        }        
    }
    
    while (que.size()) {
        que.pop();
    }
    
    total = 0;
    for (int i = last + 1; i < C; i++) {
        total += cow[i].second;
        que.push(cow[i].second);
    }
    
    for (int i = last; i >= first; i--) {
        upper[i] = total;
        int aid = cow[i].second;
        int top = que.top();
        if (aid < top) {
            que.pop();
            que.push(aid);
            total = total - top + aid;
        }
    }
    
    int res = -1;
    for (int i = last; i >= first; i--) {
        if (lower[i] + cow[i].second + upper[i] <= F) {
            res = cow[i].first;
            break;
        }
    }
    cout << res;
    return 0;
}

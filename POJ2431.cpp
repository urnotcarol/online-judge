#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
int N;
pair<int, int> stop[MAX_N + 4];
int L;
int P;

void solve() {
    priority_queue<int> que;
    
    stop[N].first = L;
    stop[N].second = 0;
    N++;
    
    int ans = 0;
    int pos = 0;
    int tank = P;
    
    for (int i = 0; i < N; i++) {
        int d = stop[i].first - pos;  //distance to next fuel stop
        while (tank < d) {
            if (que.empty()) {
                printf("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        
        tank -= d;
        pos = stop[i].first;
        que.push(stop[i].second);
    }
    
    printf("%d", ans);
}

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &stop[i].first, &stop[i].second);        
    }
    scanf("%d %d", &L, &P);

    for (int i = 0; i < N; i++) {
        stop[i].first = L - stop[i].first;
    }
    sort(stop, stop + N);
    solve();
    return 0;
}

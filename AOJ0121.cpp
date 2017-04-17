#include <iostream>
#include <stdio.h>
#include <queue> 

using namespace std;

const int MAX_S = 40320 + 16;
const int INF = 0x3f3f3f3f;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int a[16];
int n = 7;
int dp[MAX_S];

struct State {
    int a[16];
    int pos;
    int contor() {
        int res = 0;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[i]) {
                    count++;
                }
            }
            res += count * fact[n - i];         
        }
        return res;
    }
};
int dx[4] = {1, -1, 4, -4};

void bfs() {
    State ini;
    for (int i = 0; i <= n; i++) {
        ini.a[i] = i;
    }
    ini.pos = 0;
    queue<State> que;
    que.push(ini);
    dp[0] = 0;
    while(!que.empty()) {
        State cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int p = cur.pos + dx[i];
            if (p >= 0 && p <= 7 
                && !(cur.pos == 3 && p == 4) 
                && !(cur.pos == 4 && p == 3)) {
                State next = cur;
                swap(next.a[p], next.a[cur.pos]);
                next.pos = p;
                int contorH = next.contor();
                if (dp[contorH] == INF) {
                    dp[contorH] = dp[cur.contor()] + 1;
                    que.push(next);
                }
            }
        }
    }
}

int main() {
    fill(dp, dp + MAX_S, INF);
    string line;
    bfs();
    while(getline(cin, line)) {
        State cur;
        for (int i = 0; i <= n; i++) {
            cur.a[i] = line[2 * i] - '0';
        }
        printf("%d\n", dp[cur.contor()]);
    }
} 

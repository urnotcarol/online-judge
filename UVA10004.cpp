#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int MAX_N = 200 + 4;
int n;
int l;

vector<int> G[MAX_N];
int color[MAX_N];

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        if (color[G[v][i]] == c) {
            return false;
        }
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) {
            return false;
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

int main () {
    while(scanf("%d", &n) && n > 0) {
        for (int i = 0; i < MAX_N; i++) {
            G[i].clear();
        }
        memset(color, 0, sizeof(color));
        scanf("%d", &l);
        int a;
        int b;
        for (int i = 0; i < l; i++) {
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if (solve()) {
            printf("BICOLORABLE.\n");
        }
        else {
            printf("NOT BICOLORABLE.\n");
        }        
    }
    return 0;
}

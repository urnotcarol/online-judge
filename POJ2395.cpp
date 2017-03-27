#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ONLINE_JUDGE

using namespace std;

const int MAX_N = 2000 + 4;
const int MAX_M = 10000 + 4;

int N;
int M;

struct Edge {
    int u, v, cost;
};
bool comp(Edge & e1, Edge & e2) {
    return e1.cost < e2.cost;
}

Edge edge[MAX_M];

int par[MAX_N];
int rank[MAX_N];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (rank[x] > rank[y]) {
        par[y] = x;
    } 
    else {
        par[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int kruskal() {
    init(N);
    int res = 0;
    sort(edge, edge + M, comp);
    for (int i = 0; i < M; i++) {
        Edge e = edge[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res = max(res, e.cost);
        }
    }
    return res;
}

int main() { 
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    
    scanf("%d %d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++) {        
        scanf("%d %d %d", &u, &v, &edge[i].cost);
        u--;
        v--;
        edge[i].u = u;
        edge[i].v = v;
    }
    int res = kruskal();
    printf("%d", res);
    
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

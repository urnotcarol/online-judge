#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

#define ONLINE_JUDGE 
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 20000 + 4;
int T;
int N, M, R;
struct Edge {
    int from;
    int to;
    int cost;
    Edge() {}
    Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};
vector<Edge> edge;

bool comp(Edge & e1, Edge & e2) {
    return e1.cost < e2.cost;
}

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
    if (rank[x] < rank[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}
 
int kruskal () {
    sort(edge.begin(), edge.end(), comp);
    init(N + M);
    int res = 0;
    int E = edge.size();
    for (int i = 0; i < E; i++) {
        Edge e = edge[i];
        if (!same(e.from, e.to)) {
            res += e.cost;
            unite(e.from, e.to);
        }
    }
    return res;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &R);
        int from, to, cost;
        edge.clear();
        for (int i = 0; i < R; i++) {
            scanf("%d %d %d", &from, &to, &cost);
            to += N;
            edge.push_back(Edge(from, to, -cost));
        }
        int res = kruskal();
        printf("%d\n", (N + M) * 10000 + res);        
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

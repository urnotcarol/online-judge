#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 100000 + 16;
const int MAX_M = 200000 + 16;

int n;
int m;
struct Edge {
    int u, v, cost;
    Edge() {}
    Edge(int u, int v, int cost): u(u), v(v), cost(cost) {} 
    bool operator> (const Edge & e) const {
        return cost > e.cost;
    } 
};
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
    return find(par[x]);
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

int main() {
    scanf("%d %d", &n, &m);
    init(n + 1);
    int u, v, cost;
    priority_queue<Edge, vector<Edge>, greater<Edge> > que;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        que.push(Edge(u, v, cost));
    }
    
    int res = 0;
    while (!que.empty()) {
        Edge e = que.top();
        que.pop();
        unite(e.u, e.v);
        if (same(1, n)) {
            res = e.cost;
            break;
        }        
    }
    cout << res;
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define ONLINE_JUDGE

using namespace std;

const int MAX_N = 1000 + 4;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to;
    int cost;
    Edge() {}
    Edge(int to, int cost): to(to), cost(cost) {}
};
vector<Edge> G[MAX_N];

int minCost[MAX_N];
bool used[MAX_N];
typedef pair<int, int> P;
int N;
int M;

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

 
int prim() {
    fill(minCost, minCost + N, INF);
    fill(used, used + N, false);
    minCost[0] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, 0));
    
    int res = 0;
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (minCost[v] < p.first) {
            continue;
        }
        used[v] = true;
        res += p.first;
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (!used[e.to] && minCost[e.to] > e.cost) {
                minCost[e.to] = e.cost;
                que.push(P(minCost[e.to], e.to));
            }
        }
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d %d", &N, &M);
    init(N);
    int from, to, cost;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        from--;
        to--;
        unite(from, to);
        G[from].push_back(Edge(to, -cost));
        G[to].push_back(Edge(from, -cost));
    }
    int res = -1;
    bool connected = true;
    for (int i = 1; i < N; i++) {
        if (!same(0, i)) {
            connected = false;
            break;
        }
    }
    if (connected) {
        res = -prim();
    }
    cout << res;
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

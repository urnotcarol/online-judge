#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

//#define ONLINE_JUDGE

using namespace std;

const int MAX_N = 10000 + 4;
int N;
int M;
struct P {
    int x, y;
    P() {}
    P(int x, int y): x(x), y(y) {}
};

struct Edge {
    int u, v;
    double cost;
    Edge() {}
    Edge(int u, int v, double cost): u(u), v(v), cost(cost) {}
};

bool comp(Edge & e1, Edge & e2) {
    return e1.cost < e2.cost;
}

P pile[MAX_N];
vector<Edge> edge;
double sum;
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

void kruskal() {
    init(N);
    sort(edge.begin(), edge.end(), comp);
    for (int i = 0; i < edge.size(); i++) {
        Edge e = edge[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            sum -= e.cost;
        }        
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d %d", &N, &M);
    int x, y;
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &pile[i].x, &pile[i].y);
    }
    int u, v;
    double cost;
    sum = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        cost = -sqrt(pow((pile[u].x - pile[v].x), 2) + pow((pile[u].y - pile[v].y), 2));
        sum += cost;
        edge.push_back(Edge(u, v, cost));
    }
    kruskal();
    
    if (sum == 0.0) {
        printf("0.000");
    }
    else {
        printf("%.3lf", -sum);
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

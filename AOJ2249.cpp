#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
#define ONLINE_JUDGE
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 10000 + 4;
struct Edge {
    int to;
    int cost;
    int distance;
    Edge() {}
    Edge(int to, int cost, int distance): to(to), cost(cost), distance(distance) {}
};
typedef pair<int, int> P;
vector<Edge> G[MAX_N];
int d[MAX_N];
int N;
int M;

void dijkrast(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + MAX_N, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.distance) {
                d[e.to] = d[v] + e.distance;
                que.push(P(d[e.to], e.to));
            }
        }
    }     
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while (scanf("%d %d", &N, &M) && N) {
        for (int i = 0; i < MAX_N; i++) {
            G[i].clear();
        }
        int u, v, distance, cost;
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d %d", &u, &v, &distance, &cost);
            G[u].push_back(Edge(v, cost, distance));
            G[v].push_back(Edge(u, cost, distance));
        }
        dijkrast(1);
        int res = 0;
        for (int i = 2; i <= N; i++) {
            int minCost = INF;
            for (int j = 0; j < G[i].size(); j++) {
                if (d[i] == d[G[i][j].to] + G[i][j].distance) {
                    minCost = min(minCost, G[i][j].cost);
                }
            }
            res += minCost;
        }
        printf("%d\n", res);
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define ONLINE_JUDGE

using namespace std;

const int MAX_N = 100 + 4;
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
    while (1) {
        if (scanf("%d", &N) == EOF) {
            break;
        }
        int cost;
        for (int i = 0; i < N; i++) {
            G[i].clear();
            for (int j = 0; j < N; j++) {
                scanf("%d", &cost);
                if (i != j) {
                    G[i].push_back(Edge(j, cost));
                }
            }
        }
        int res = prim();
        printf("%d\n", res);
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

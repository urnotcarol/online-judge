#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define ONLINE_JUDGE
using namespace std;

const int MAX_N = 500 + 4;
const int INF = 0x3f3f3f3f;

struct Edge {
    int from;
    int to;
    int cost;
    Edge() {}
    Edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

vector<Edge> edge;
int d[MAX_N];
int F;
int N;
int M;
int W;

bool BellmanFord () {
    memset(d, 0, sizeof(d));
    for (int v = 0; v < N; v++) {
        for (int i = 0; i < edge.size(); i++) {
            Edge e = edge[i];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                if (v == N - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d", &F);
    while (F--) {
        edge.clear();
        scanf("%d %d %d", &N, &M, &W);
        int from, to, cost;
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &from, &to, &cost); 
            Edge e1(from, to, cost);
            Edge e2(to, from, cost);
            edge.push_back(e1);
            edge.push_back(e2);
        }
        for (int i = 0; i < W; i++) {
            scanf("%d %d %d", &from, &to, &cost);
            Edge e(from, to, -cost);
            edge.push_back(e);
        }
        bool res = BellmanFord();
        if (res) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    #endif
    return 0;
}

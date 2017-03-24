#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ONLINE_JUDGE
using namespace std;

const int MAX_E =  (301 * 300) / 2 + 4;
const int MAX_N = 300 + 4;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> Edge;
vector<pair<int, int> > edge;
int d[MAX_N];
int cow[MAX_N];
int N;
int M;
 
int BellmanFord(int s) {
    fill(d, d + MAX_N, INF);
    d[s] = 0;

    while (true) {
        bool update = false;
        for (int i = 0; i < edge.size(); i++) {
            Edge e = edge[i];
            if (d[e.first] != INF && d[e.second] > d[e.first] + 1) {
                update = true;
                d[e.second] = d[e.first] + 1;
            }
        }
        if (!update) {
            break;
        }
    }
    
    int res = 0;
    for (int i = 0; i < N; i++) {
        res += d[i + 1];
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d %d", &N, &M);
    int num;
    N = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &cow[j]);
            N = max(N, cow[j]);
        }
        for (int j = 0; j < num - 1; j++) {
            for (int k = j + 1; k < num; k++) {
                edge.push_back(Edge(cow[j], cow[k]));
                edge.push_back(Edge(cow[k], cow[j]));
            }
        }
    }
    int popular = INF;
    for (int i = 0; i < N; i++) {
        popular = min(popular, BellmanFord(i + 1));
    }
    printf("%d", 100 * popular / (N - 1));
    return 0;
}

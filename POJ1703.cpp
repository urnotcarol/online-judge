#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_N = 100000;
int T;
int N;
int M;

int par[MAX_N * 2 + 4];
int rank[MAX_N * 2 + 4];

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

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        init(N * 2);
        char message;
        int a;
        int b;
        cin.ignore();
        for (int i = 0; i < M; i++) {
            scanf("%c %d %d", &message, &a, &b);
            a--;
            b--;
            if (message == 'D') {
                unite(a, b + N);
                unite(a + N, b);
            }
            else {
                if (same(a, b)) {
                    printf("In the same gang. \n");
                }
                else if (same(a, b + N)) {
                    printf("In different gangs.\n");
                }
                else {
                    printf("Not sure yet.\n");
                }                
            }
            cin.ignore();
        }
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>

using namespace std;

const int MAX_N = 1001;
int N;
int d;
int x[MAX_N + 4];
int y[MAX_N + 4];
bool repaired[MAX_N + 4];
bool reach[MAX_N +4][MAX_N + 4];

int par[MAX_N + 4];
int rank[MAX_N + 4];

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
    scanf("%d %d", &N, &d);
    init(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (sqrt((double)((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))) <= d) {
                reach[i][j] = true;
                reach[j][i] = true;
            }
        }
    }
    cin.ignore();
    char operation;
    while (scanf("%c", &operation) != EOF) {                 
        if (operation == 'O') {
            int x;
            scanf("%d", &x);
            repaired[x] = true;
            for (int i = 1; i <= N; i++) {
                if (i == x) {
                    continue;
                }
                
                if (reach[x][i] && repaired[i]) {
                    unite(i, x);                    
                }
            }            
        }
        else if (operation == 'S') {
            int p;
            int q;
            scanf("%d %d", &p, &q);         
            if (same(p, q)) {
                printf("SUCCESS\n");
            } 
            else {
                printf("FAIL\n");
            }                      
        }
        cin.ignore();
    }
    return 0;
} 

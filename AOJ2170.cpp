#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int MAX_N = 100000;
int N;
int Q;
bool marked[MAX_N + 4];
int par[MAX_N + 4];

int find(int x) {
    if (marked[x]) {
        return x;
    }
    return find(par[x]);
}

int main() {
    while (scanf("%d %d", &N, &Q) != EOF && N > 0 && Q > 0) {
        memset(marked, 0, sizeof(marked));
        marked[1] = 1;
        long long res = 0;
        for (int i = 2; i <= N; i++) {
            scanf("%d", &par[i]);
        }
        par[1] = 1;
        cin.ignore();
        char operation;
        int node;
        for (int i = 0; i < Q; i++) {
            scanf("%c %d", &operation, &node);
            if (operation == 'Q') {
                res += find(node);
            }
            else if (operation == 'M') {
                marked[node] = true;
            }
            cin.ignore();
        }
        cout << res << endl;
    }
    return 0;
}

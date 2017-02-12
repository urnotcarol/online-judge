#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 350;
int n;
int tri[MAX_N + 3][MAX_N + 3];
int dp[MAX_N + 3][MAX_N + 3];

void solve() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[n][i]);
    }
    printf("%d", res);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &tri[i][j]);
        }
    }
    solve();
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100000;
int n;
int m;
int a[MAX_N + 3];
int c[MAX_N + 3];
int dp[MAX_M + 3];

void solve() {
    memset(dp, -1, sizeof(dp));   
    dp[0] = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[j] >= 0) {
                dp[j] = c[i];
            }
            else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            }
            else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= m; i++) {
        if(dp[i] >= 0) {
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    while(scanf("%d %d", &n, &m) && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        solve();
    }
    return 0;    
} 

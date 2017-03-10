#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>

using namespace std;

const int MAX_T = 1000;
const int MAX_A = 100000;
const int MOD = 1000000;
int T;
int A;
int S;
int B;
int c[MAX_T + 3];
int dp[2][MAX_A + 3];

int main() {
    scanf("%d %d %d %d", &T, &A, &S, &B);
    int ant;
    for (int i = 0; i < A; i++) {
        scanf("%d", &ant);
        c[ant]++;
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= T; i++) {
        int cur = i & 0x1;
        int pre = (i - 1) & 0x1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= min(c[i], j); k++) {
                dp[cur][j] = (dp[cur][j] + dp[pre][j - k]) % MOD;
            }
        }
    }
    
    int res = 0;
    for (int i = S; i <= B; i++) {
        res += dp[T& 0x1][i] % MOD;
    }
    cout << res % MOD;
    return 0; 
}

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAX_N = 1000000;
const int MOD = 1000000000;
int n;
int dp[MAX_N + 3];

int main() {
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int j = 2; j <= n; j++) {
        if (j & 1) {
            dp[j] = dp[j - 1] % MOD;
        }
        else {
            dp[j] = (dp[j - 2] + dp[j >> 1]) % MOD;
        }

    }
    cout << dp[n];
    return 0;
}

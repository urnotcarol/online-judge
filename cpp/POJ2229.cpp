#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAX_N = 1000000;
int n;
int number[20];
int dp[MAX_N + 3];


int main() {
    for (int i = 0; i < 20; i++) {
        number[i] = 1 << i;
    }
    cin >> n;
    int m = log((float)n) / log(2.0);
    dp[0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = number[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - number[i]]) % 1000000000;
        }
    }
    cout << dp[n];
    return 0;
} 

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAX_T = 1000;
const int MAX_W = 30;
int n;
int T;
int W;
int dp[MAX_T + 3][MAX_W + 3];
int apple[MAX_T + 3];

int main() {
    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        scanf("%d", &apple[i]);
        dp[i][0] = dp[i - 1][0] + (apple[i] == 1);
        for (int j = 1; j <= W; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (apple[i] == j % 2 + 1);
        }
    }
    
    int maxA = 0;
    for (int i = 0; i <= W; i++) {
        maxA = max(maxA, dp[T][i]);
    }
    cout << maxA;
    return 0;
} 

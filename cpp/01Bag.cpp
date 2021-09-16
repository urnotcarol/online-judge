#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int MAX_N = 100;
const int MAX_W = 10000;
int n;
int W;
int w[MAX_N];
int v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

int solve1(int i, int j) {      //方法1：记忆化搜索 
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    int res;
    if (i == n) {
        res = 0;
    }
    else if (w[i] > j) {
        res = solve1(i + 1, j);
    }
    else {
        res = max(solve1(i + 1, j), solve1(i + 1, j - w[i]) + v[i]);
    }    
    return dp[i][j] = res;
}

int solve2() {              //方法2：动态规划之逆向 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } 
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    return dp[0][W];
} 

int solve3() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            }
            else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    return dp[n][W];
} 


int main() {
    scanf("%d %d", &n, &W);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    
//    memset(dp, -1, sizeof(dp));    
//    cout << solve1(0, W); 
    
//    memset(dp, 0, sizeof(dp));
//    cout << solve2();
    
    memset(dp, 0, sizeof(dp));
    cout << solve3();
       
    return 0;
} 


/*
4 5
2 3
1 2
3 4
2 2
*/

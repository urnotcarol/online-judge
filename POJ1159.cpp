#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;
int N;
char str[MAX_N + 4];
char rts[MAX_N + 4];

int dp[2][MAX_N + 4];

int main() {
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; i++) {
        scanf("%c", &str[i]);
        rts[N + 1 - i] = str[i];
    } 
    for (int i = 1; i <= N; i++) {
        int cur = i & 0x1;
        int pre = (i - 1) & 0x1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int j = 1; j <= N; j++) {
            if (str[i] == rts[j]) {
                dp[cur][j] = dp[pre][j - 1] + 1;
            }
            else {
                dp[cur][j] = max(dp[pre][j], dp[cur][j - 1]);
            }
        }
    }
    cout << N - dp[N & 0x1][N];
    return 0;
}

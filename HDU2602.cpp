#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAX_N = 1000;

int N;
int V;
int value[MAX_N + 1];
int vol[MAX_N + 1];
int dp[MAX_N + 1];
int res;

int main() {
    int input;
    cin >> input;
    while(input-- > 0) {
        cin >> N >> V;
        for (int i = 0; i < N; i++) {
            scanf("%d", &value[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &vol[i]);
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = V; j >= value[i]; j--) {
                dp[j] = max(dp[j], dp[j - vol[i]] + value[i]);
            }
        }
        printf("%d\n", dp[V]);
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}

/*
2
5 10
1 2 3 4 5
5 4 3 2 1
5 10
1 2 3 4 5
5 4 3 2 1

*/


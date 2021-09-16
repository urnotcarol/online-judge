#include <iostream> 
#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAX_N = 500;
const int MAX_E = 10000;
const int INF = 0x3f3f3f3f;
int T;
int E;
int F;
int N;
pair<int, int> coin[MAX_N + 3];
int dp[MAX_E + 3];


int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &E, &F);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &coin[i].first, &coin[i].second);
        }
        E = F - E;
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = coin[i].second; j <= E; j++) {
                dp[j] = min(dp[j], dp[j - coin[i].second] + coin[i].first);
            }
        }
        if (dp[E] != INF) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[E]);
        }
        else {
            printf("This is impossible.\n");
        }
    }
    return 0;
}

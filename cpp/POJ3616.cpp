#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_M = 1000;
int N;
int M;
int R;
struct Invl {
    int s;
    int t;
    int eff;
    bool operator < (Invl & i) {
        return s < i.s;
    }
};
Invl invl[MAX_M + 3];
int dp[MAX_M + 3];

int main() {
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &invl[i].s, &invl[i].t, &invl[i].eff);
    }
    sort(invl + 1, invl + 1 + M);
    for (int i = 1; i <= M; i++) {
        dp[i] = invl[i].eff;
        for (int j = 1; j <= i; j++) {
            if (invl[j].t + R <= invl[i].s) {
                dp[i] = max(dp[i], dp[j] + invl[i].eff); 
            }            
        }
    }
    cout << *max_element(dp + 1, dp + 1 + M);
    return 0;
}

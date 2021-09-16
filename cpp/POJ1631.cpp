#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_P = 40000;
const int INF = 0x3f3f3f3f;
int n;
int p;
int port[MAX_P + 4];
int dp[MAX_P + 4];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &p);
        for (int i = 0; i < p; i++) {
            scanf("%d", &port[i]);
            dp[i] = INF;
        }
        
        for (int i = 0; i < p; i++) {
            *lower_bound(dp, dp + p, port[i]) = port[i];
        }
        
        cout << lower_bound(dp, dp + p, INF) - dp << endl;
    }
    return 0;
}


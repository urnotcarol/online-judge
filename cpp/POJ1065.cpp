#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <functional>

using namespace std;
const int MAX_N = 5000;

int T;
int n;
pair<int, int> stick[MAX_N + 4];
int dp[MAX_N + 4];

int main() {
    scanf("%d", &T);
    while (T--) {
       scanf("%d", &n);
       for (int i = 0; i < n; i++) {
           scanf("%d %d", &stick[i].first, &stick[i].second);
        } 
        sort(stick, stick + n);
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            *lower_bound(dp, dp + n, stick[i].second, greater<int> ()) = stick[i].second;
            for (int i = 0; i < n; i++) {
                cout << dp[i] << " ";
            }
            cout << endl; 
        }
        
        cout << lower_bound(dp, dp + n, -1, greater<int> ()) - dp << endl;
    }
    return 0;
}

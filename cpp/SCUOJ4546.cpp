#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_M = 1000000 + 4;
int T;
int n, m;
int num[30];
int former[MAX_M];
int latter[MAX_M];

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        
        fill(former, former + m + 1, false);
        fill(latter, latter + m + 1, false);        
        
        bool res = false;
        
        int N1 = 1 << (n / 2);
        for (int i = 1; i < N1; i++) {
            long long sum = 0;
            for (int j = 0; j < n / 2; j++) {
                if (i & (1 << j)) {
                    sum += num[j];
                }
            }
            sum %= m;
            former[sum] = true;
        }
        
        int N2 = 1 << ((n + 1) / 2);
        for (int i = 1; i < N2; i++) {
            long long sum = 0;
            for (int j = 0; j < (n + 1) / 2; j++) {
                if (i & (1 << j)) {
                    sum += num[n / 2 + j];
                }
            }
            sum %= m;
            latter[sum] = true;
        }
        
        if (latter[0] || former[0] || latter[m] || former[m]) {
            res = true;
        }        
        else {
            for (int i = 1; i < m; i++) {
                if (former[i] && latter[m - i]) {
                    res = true;
                    break;
                }
            }
        }
        
        if (res) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}

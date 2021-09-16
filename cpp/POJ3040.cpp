#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int m = 0; //需要进行贪心的硬币 
int c;
pair<int, int> coin[20];

int solve() {
    int res = 0;
    sort(coin, coin + m);
    int need = c;
    while (1) {
        for (int i = m - 1; i >= 0; --i) {   
            if (need > 0 && coin[i].second > 0) {
                int t = min(coin[i].second, need / coin[i].first);
                need -= t * coin[i].first;
                coin[i].second -= t;  
            }   
        } 
        for (int i = 0; i < m; i++) {
            if (need > 0 && coin[i].second > 0) {
                int t = min(coin[i].second, (int)ceil((double)need / (double)(coin[i].first)));
                need -= t * coin[i].first;
                coin[i].second -= t;     
            }
            
        }
        if (need > 0) {
            break;
        }
        res++;
        need = c;  
    }
    return res;
}

int main() {
    int res = 0;
    int v;
    int b;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v, &b);
        if (v >= c) {
            res += b;
        }
        else {
            coin[m].first = v;
            coin[m].second = b;
            m++;
        }
    }
    res += solve();
    
    printf("%d\n", res); 
    return 0;
} 

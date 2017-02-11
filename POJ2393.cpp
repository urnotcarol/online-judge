#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
int s;
ll c[10005];
ll y[10005];

void solve() {
    ll res = 0; 
    
    for (int i = 1; i < n; i++) {
        c[i] = min(c[i], c[i - 1] + s);
    } 
    for (int i = 0; i < n; i++) {
        res += c[i] * y[i];
    }

    printf("%lld\n", res);
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c[i], &y[i]);
    }
    solve();
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int r;
int n;
int x[1000];

void solve() {
    int res = 0;
    sort(x, x + n);
    
    int i = 0;
    while (i < n) {
        int s = x[i++];
        while (i < n && x[i] <= s + r) {
            i++;
        }
        int p = x[i - 1];
        while (i < n && x[i] <= p + r) {
            i++;
        }
        res++;        
    }
    cout << res << endl;
}

int main() {
    while (cin >> r >> n && r != -1) {
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        
        solve();
    }
    return 0;
}

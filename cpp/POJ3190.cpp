#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
struct cow {
    int first;
    int second;
    int index;
    bool operator < (const cow &c) {
        return first < c.first;
    }
};
cow invl[50000];
pair<int, int> stall[50001];
int assigned[50000];

void solve() {
    int res = 1;
    sort(invl, invl + n);
    for (int i = 0; i < n; i++) {
        bool hasFound = 0;
        int s = invl[i].first;      
        int t = invl[i].second;
        int cowIndex = invl[i].index;
        
        for (int j = 1; j <= res; j++) {            
            if (s > stall[j].second) {
                stall[j].second = t;
                hasFound = 1;
                assigned[cowIndex] = j;
                break;
            }
        }
        
        if (hasFound == 0) {
            res++;
            stall[res].first = s;
            stall[res].second = t;
            assigned[cowIndex] = res;
        }              
    }
    printf("%d\n", res);
    for (int i = 0; i < n; i++) {
        printf("%d\n", assigned[i]);
    } 
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &invl[i].first);
        scanf("%d", &invl[i].second);
        invl[i].index = i;
    }
    solve();
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int t;
pair<int, int> invl[25000]; 

void slove() {
    sort(invl, invl + n);
    int res = 0;
    int cur = 0;
    
    while (cur < t) {      
        int maxT = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (invl[i].first <= cur + 1 && invl[i].second > cur) {
                count++;
                maxT = max(maxT, invl[i].second);
            }
        }
        
        if (count == 0) {
            printf("-1");
            return;
        }
        cur = maxT;
        res++;
    }
    
    printf("%d", res);
}

int main() {
    scanf("%d %d", &n, &t);
    int maxT = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &invl[i].first, &invl[i].second);
        maxT = max(maxT, invl[i].second);
    }
    if (maxT < t) {
        printf("-1");
    } 
    else {
        slove();
    }
    return 0;    
}

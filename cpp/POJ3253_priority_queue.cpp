#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 20000;
int N;
int wood[MAX_N + 4];

int main() {
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int> > pque;
    for (int i = 0; i < N; i++) {
        scanf("%d", &wood[i]);
        pque.push(wood[i]);
    }
    int minW;
    int nextMinW;
    long long res = 0;
    while(pque.size() > 1) {
        minW = pque.top();
        pque.pop();
        nextMinW = pque.top();
        pque.pop();
        res += minW + nextMinW;
        pque.push(minW + nextMinW);
    }
    cout << res;    
    return 0;
}

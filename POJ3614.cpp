#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_C = 2500;
const int MAX_L = 2500;
int C;
int L;
struct Cow {
    int minSPF;
    int maxSPF;
    bool operator < (Cow & c) {
        bool res;
        if (maxSPF > c.minSPF) {
            res = true;
        }
        else if (minSPF < c.minSPF) {
            res = false;
        }
        else if (minSPF == c.minSPF) {
            if (maxSPF > c.maxSPF) {
                res = true;
            }
            else {
                res = false;
            }
        }
        return res;
    }
};
Cow cow[MAX_C + 4];
pair<int, int> lotion[MAX_L + 4];

int main() {
    scanf("%d %d", &C, &L);
    for (int i = 0; i < C; i++) {
        scanf("%d %d", &cow[i].minSPF, &cow[i].maxSPF);
    }
    
    priority_queue<int> que;
    for (int i = 0; i < L; i++) {
        scanf("%d %d", &lotion[i].first, &lotion[i].second);
        que.push(lotion[i].first);
    }
    sort(cow, cow + C);
    queue<int> tempQue;
    int res = 0;
    for (int i = 0; i < C; i++) {
        while (que.size() > 0) {
            int SPF = que.top();
            if (SPF > cow[i].maxSPF) {
                tempQue.push(que.top());
                que.pop();
                continue;
            }   
            else if (SPF < cow[i].minSPF) {
                break;
            }
            else {
//                res++;
                for (int i = 0; i < L; i++) {
                    if (lotion[i].first == que.top() && lotion[i].second > 0) {
                        lotion[i].second--;   
                        res++; 
                        if (lotion[i].second == 0) {
                            que.pop();
                        }    
                        break;               
                    }
                }
                break;
            }
        }
        while (tempQue.size() > 0) {
            que.push(tempQue.front());
            tempQue.pop();
        }
    }
    cout << res;
    return 0;
}

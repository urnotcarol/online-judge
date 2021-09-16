#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

struct State {
    bool hasMoved;
    bool hasLifted;
    bool canThrow;
    bool able;
    State() {
        hasMoved = false;
        hasLifted = false;
        canThrow = false;
        able = true;
    }
}; 
State s[4];

int pos[4]; //current position
int mr[4];  //move range
int tr[4];  //throw range
int p[4];   //lift which one
int res = 0;

bool near(int s) {
    for (int i = 1; i <= 3; i++) {
        if (abs(pos[i] - s) == 1) {
            return true;
        }
    }
    return false;    
}

void dfs() {
    for (int i = 1; i <= 3; i++) {
        res = max(res, pos[i]);
    } 
    for (int i = 1; i <= 3; i++) {
        if (s[i].able == false) {
            continue;
        }
        
        if (s[i].hasMoved == false && s[i].canThrow == false) {
            for (int j = -mr[i]; j <= mr[i]; j++) {
                if (j == 0) {
                    continue;
                }
                pos[i] += j;
                s[i].hasMoved = true;
                if (near(pos[i]) || j == mr[i] || j == -mr[i]) {
                    dfs();
                }
                pos[i] -= j;
                s[i].hasMoved = false;               
            }
        }  
        
        if (s[i].hasLifted == false) {
            for (int j = 1; j <= 3; j++) {
                if (s[j].able == true && abs(pos[i] - pos[j]) == 1) {
                    s[j].able = false;
                    s[i].hasLifted = true;
                    s[i].canThrow = true;
                    p[i] = j;
                    int temp = pos[j];
                    dfs();
                    pos[j] = temp;
                    s[i].canThrow = false;
                    s[i].hasLifted = false;
                    s[j].able = true; 
                }
            }
        }
        
        if (s[i].canThrow) {
            for (int j = -tr[i]; j <= tr[i]; j++) {
                if (j == 0) {
                    continue;
                }
                s[p[i]].able = true;
                s[i].canThrow = false;
                int temp = pos[p[i]];
                pos[p[i]] = pos[i] + j;
                if (near(pos[p[i]]) || j == -tr[i] || j == tr[i]) {
                    dfs();
                }
                pos[p[i]] = temp;
                s[i].canThrow = true;
                s[p[i]].able = false;                   
            }
        }
    }
    return;
}

int main() {
    for (int i = 1; i <= 3; i++) {
        scanf("%d %d %d", &pos[i], &mr[i], &tr[i]);
    }
    dfs();  
    cout << res;
    return 0;    
}



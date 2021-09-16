#include <iostream>
#include <stdio.h>

using namespace std;

int w;
int h;
const int INF = 0x3f3f3f3f;
int goal;
int res[100];
int sx;
int sy;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int board[25][25];

bool isNotOut(int x, int y) {
    if(x < 0 || y < 0 || x >= h || y >= w) {
        return false;
    }
    return true;
}


void dfs(int step, int x, int y) {
    int nx;
    int ny;
    
    if(step > 10) {
        return ;
    }
    
    for(int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(!isNotOut(nx, ny)) {
            continue;  
        }
        if(board[nx][ny] == 1) {
            continue;
        }
        while(!board[nx][ny]) {
            nx += dx[i];
            ny += dy[i];
            if(!isNotOut(nx, ny)) {
                break;
            }
        } 
        if(isNotOut(nx, ny)) {
            if(board[nx][ny] == 3) {
                goal = min(goal, step);
            }
            if(board[nx][ny] == 1) {
                board[nx][ny] = 0;
                dfs(step + 1, nx - dx[i], ny - dy[i]);
                board[nx][ny] = 1;
            }
        }
    }
}

int main() {
    int n = 0;
    while(scanf("%d %d", &w, &h) != EOF) {
        if(w == 0 && h == 0) {
            break;
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%d", &board[i][j]);
                if(board[i][j] == 2) {
                    sx = i;
                    sy = j;
                    board[i][j] = 0;
                }
            }
        }
        goal = INF;
        dfs(1, sx, sy);   
        res[n] = goal;
        n++;    
    }
    for (int i = 0; i < n; i++) {
        if(res[i] != INF) {
            printf("%d\n", res[i]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
} 



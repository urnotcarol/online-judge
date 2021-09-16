#include <iostream>

using namespace std;

int w[100000000];
int h[100000000];
int res[100000000];
char tiles[20][20];

void dfs(int index, int x, int y) {
    tiles[x][y] = '#';
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < h[index] && ny < w[index] && tiles[nx][ny] == '.') {
            res[index]++;
            dfs(index, nx, ny);
        }
    } 
    return;
}

void solve(int index) {
    res[index] = 1;
    for (int i = 0; i < h[index]; i++) {
        for (int j = 0; j < w[index]; j++) {
            if (tiles[i][j] == '@') {
                dfs(index, i, j);
            }
        }
    }
} 
int main() {
    int index = 0;
    do {
        cin >> w[index] >> h[index];
         for (int i = 0; i < h[index]; i++) {
            for (int j = 0; j < w[index]; j++) {
               cin >> tiles[i][j]; 
           }
        }
        solve(index);
        index++;
    } 
    while (w[index - 1] > 0 && h[index - 1] > 0);
    
    for (int i = 0; i < index -1; i++) {
        cout << res[i] << endl;
    }

    return 0;
} 




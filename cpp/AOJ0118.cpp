#include <iostream>
#include <cstdio>

using namespace std;
int h;
int w;
int res = 0;
char field[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    int nx;
    int ny;
    char temp = field[x][y];
    field[x][y] = '.';
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && field[nx][ny] == temp) {
            dfs(nx, ny);
        }
    }   
    return;
}

int main() {
    while (1) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> field[i][j];
            }
        }
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (field[i][j] != '.') {
                    dfs(i, j);
                    res++;
                }
            }
        }
        cout << res << endl;
        res = 0;
    } 
    return 0;
} 


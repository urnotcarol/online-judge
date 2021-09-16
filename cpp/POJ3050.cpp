#include <iostream>
#include <set>
#include <string>
#include <math.h>

using namespace std;

int grid[5][5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char digits[6];
set<string> integers; 

void dfs(int x, int y, int n) {
    if (n == 6) {
        string temp = digits;
        integers.insert(temp);
        pow(10)
        return;
    }
    digits[n] = grid[x][y] + '0';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            dfs(nx, ny, n + 1);
        }
    }      
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 0);
        }
    }   
    cout << integers.size();
    return 0; 
}



#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int m;
int n;
const int INF = 0x3f3f3f3f;
char maze[100][100];
int d[100][100];
int sx, sy;
int gx, gy;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef pair<int, int> P;

void bfs() {
    queue<P> q;
    q.push(P(sx, sy));
    d[sx][sy] = 0;

    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == gx && y == gy) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                q.push(P(nx, ny));
                d[nx][ny] = d[x][y] + 1;
            }
        }

    }

}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            d[i][j] = INF;
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    bfs();
    cout << d[gx][gy];
    return 0;
}

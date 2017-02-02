#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

const int MAX_INDEX = 512;
int eMap[MAX_INDEX][MAX_INDEX];
bool visited[MAX_INDEX][MAX_INDEX];

struct Meteor {
    int x;
    int y;
    int t;
};

typedef Meteor P;

Meteor input[50000];
int n;
int last = 0;

int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, -1, 0, 1, 0};

int bfs() {
    memset(visited, 0, sizeof(visited));
    queue<P> que;
    P cur;
    cur.x = 0;
    cur.y = 0;
    cur.t = 0;
    que.push(cur);
    
    while (que.size()) {        
        for (int i = 0; i < 4; i++) {
            cur = que.front();
            cur.x += dx[i];
            cur.y += dy[i];
            cur.t++;
            if (cur.x >= 0 && cur.y >= 0 && cur.t < eMap[cur.x][cur.y] && !visited[cur.x][cur.y]) {
                visited[cur.x][cur.y] = true;
                if (eMap[cur.x][cur.y] > last) {
                    return cur.t;
                }                
                que.push(cur);
            }
        }        
        que.pop();
    }
    return -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i].x >> input[i].y >> input[i].t;
    }
    
    memset(eMap, 0x7f, sizeof(eMap));   //将地图上所有点的值设为极大值（按题意只需大于1000就可） 
    for (int i = 0; i < n; i++) {       //创建地图 
        last = max(last, input[i].t);   //last变量记录流星下落的最晚时间 
        for (int j = 0; j < 5; j++) {
            int nx = input[i].x + dx[j];
            int ny = input[i].y + dy[j];
            if (nx >= 0 && ny >= 0 && eMap[nx][ny] > input[i].t) {
                eMap[nx][ny] = input[i].t;
            }
        }     
    }
    
    if (eMap[0][0] == 0) {
        return -1;
    } 
    else { 
        cout << bfs() << endl;
    }
    
    return 0;
}

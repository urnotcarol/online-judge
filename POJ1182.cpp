#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_N = 50000;
const int MAX_K = 100000;
int N;
int K;
int D;
int X;
int Y;

//���鼯 
int par[MAX_N * 3 + 4];
int rank[MAX_N * 3 + 4];

//��ʼ��n��Ԫ�� 
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

//��ѯ���ĸ�
int find(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = find(par[x]);
} 

//�ϲ�x��y�����ļ���
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (rank[x] < rank[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }
} 

//�ж�x��y�Ƿ�����ͬһ������
bool same(int x, int y) {
    return find(x) == find(y);
} 
 
int main() {
    scanf("%d %d", &N, &K);
    init(N * 3);
    int ans = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d %d %d", &D, &X, &Y);
        X--;
        Y--;
        
        if (X < 0 || X >= N || Y < 0 || Y >= N) {
            ans++;   
            continue;
        }
        
        if (D == 1) {
            if (same(X, Y + N) || same(X, Y + 2 * N)) {
                ans++;
            }
            else {
                unite(X, Y);
                unite(X + N, Y + N);
                unite(X + 2 * N, Y + 2 * N);
            }
        }
        else {
            if (same(X, Y) || same(X, Y +  2 * N)) {
                ans++;
            }
            else {
                unite(X, Y + N);
                unite(X + N, Y + 2 * N);
                unite(X + 2 * N, Y); 
            }
        }
    }
    printf("%d", ans);
    return 0;
}

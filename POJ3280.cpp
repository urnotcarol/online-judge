#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_M = 2000;
int N;
int M;
char tag[MAX_M + 3];
int dp[MAX_M + 3][MAX_M + 3];
int cost[26 + 3];

int main() {
    scanf("%d %d", &N, &M);
    cin.ignore();
    for (int i = 0; i < M; i++) {
        scanf("%c", &tag[i]); 
    }
    cin.ignore();
    
    char tempChar;
    int add;
    int del;
    for (int i = 0; i < N; i++) {
        scanf("%c %d %d", &tempChar, &add, &del);
        cost[tempChar - 'a'] = min(add, del);
        cin.ignore();
    }
    
    for (int i = M - 1; i >= 0; i--) {
        for (int j = i + 1; j < M; j++) {
            if (tag[i] == tag[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i][j - 1] + cost[tag[j] - 'a'], dp[i + 1][j] + cost[tag[i] - 'a']);
            }
        }
    }
    
    cout << dp[0][M - 1];
    
    return 0; 
    
} 

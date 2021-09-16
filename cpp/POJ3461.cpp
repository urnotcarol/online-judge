#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;

const int MAX_N = 1000000 + 16;

char W[MAX_N];
char T[MAX_N];
int Pi[MAX_N];

void computePrefix(char * P) {
    memset(Pi, 0, sizeof(Pi));
    int n = strlen(P);
    int k = 0;
    Pi[0] = 0;
    for (int q = 1; q < n; q++) {
        while (k > 0 && P[q] != P[k]) {
            k = Pi[k - 1];
        }
        if (P[q] == P[k]) {
            k++;
        }
        Pi[q] = k;
    }
}

int KMP(char * T, char * P) {
    int res = 0;
    int n = strlen(T);
    int m = strlen(P);
    int q = 0;       //numbers of characters matched
    computePrefix(P);
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = Pi[q - 1];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == m) {
            res++;
            q = Pi[q - 1];
        }
    }
    return res;
}

int main() {
    int C;
    scanf("%d", &C);
    while (C--) {
        scanf("%s", W);
        scanf("%s", T);
        printf("%d\n", KMP(T, W));
    }
    return 0;
}

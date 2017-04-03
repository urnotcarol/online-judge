#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAX_N = 110000 + 16;
int p[MAX_N * 2];
char s[MAX_N * 2];

int main() {
    while (scanf("%s", s) != EOF) {  
        int len = strlen(s);      
        for (int i = len; i >= 0; i--) {
            s[i + i + 2] = s[i];
            s[i + i + 1] = '#';
        }
        s[0] = '$';
        int id = 0;
        int maxLen = 0;
        for (int i = 2; i < 2 * len + 1; i++) {
            if (i < id + p[id]) {
                p[i] = min(p[id] + id - i, p[2 * id - i]);
            }
            else {
                p[i] = 1;
            }
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (id + p[id] < i + p[i]) {
                id = i;
            }
            if (maxLen < p[i]) {
                maxLen = p[i];
            }
        } 
                  
        cout << maxLen - 1 << endl;
    }
    return 0;
}

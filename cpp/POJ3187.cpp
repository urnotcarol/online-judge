#include <iostream>
#include <algorithm>

using namespace std;

int n;
int sum;
int mycase[11][11];

int main() {
    cin >> n >> sum;
    for (int i = 1; i <= n; i++) {
        mycase[n][i] = i;
    } 
    do {
        for (int i = n; i > 1; i--) {
            for (int j = 1; j < i; j++) {
                mycase[i - 1][j] = mycase[i][j] + mycase[i][j + 1];
            }
        }
        if (mycase[1][1] == sum) {
            for (int i = 1; i <= n; i++) {
                cout << mycase[n][i] << " ";
            }
            break;
        }
    } while (next_permutation(mycase[n] + 1, mycase[n] + 1 + n));
    return 0;
}

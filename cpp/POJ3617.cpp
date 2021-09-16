#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2000;
int n;
char input[MAX_N + 1];
char res[MAX_N + 1];

void solve() {
    int l = 0;
    int r = n - 1;
    int count = 0;
    
    while (l <= r) {
        bool left = false;
        for (int i = 0; l + i <= r; i++) {
            if (input[l + i] < input[r - i]) {
                left = true;
                break;
            } 
            else if (input[l + i] > input[r - i]) {
                left = false;
                break;
            }
        }
        if (left) {
            cout << (char)input[l++];
        }
        else {
            cout << (char)input[r--];
        }
        if (++count % 80 == 0) {
            cout << endl;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }    
    solve();
    return 0;
}


/*
7
D
C
B
C
A
C
D

16
ABCDEGHABIFEDCBA
200
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
A
B
C
D
W
F
R
W
Q
S
*/

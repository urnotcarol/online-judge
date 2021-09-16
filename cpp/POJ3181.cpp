#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int MAX_D = 35;
class Bign {
public:
    int num[MAX_D];
    Bign() {
        memset(num, 0, sizeof(num));
    }
    void operator = (int input[MAX_D]) {
        for (int i = 0; i < MAX_D; i++) {
            num[i] = input[i];
        }
    }
    Bign operator + (Bign & p) {
        Bign res;
        int carry = 0;
        int mod = 0;
        for (int i = MAX_D - 1; i >= 0; i--) {
            int sum = num[i] + p.num[i] + carry;
            mod = sum % 10;
            carry = sum / 10; 
            res.num[i] = mod;
        }
        return res;
    }
};

const int MAX_N = 1000;
const int MAX_K = 100;
int N;
int K;
Bign dp[MAX_N + 4];

void solve() {
    dp[0].num[MAX_D - 1]= 1;
    for (int i = 1; i <= K; i++) {
        for (int j = i; j <= N; j++) {
            dp[j] = dp[j] + dp[j - i];
        }
    }
    
    int s;
    for (int i = 0; i < MAX_D; i++) {
        if (dp[N].num[i]) {
            s = i;
            break;
        } 
    } 
    for (int i = s; i < MAX_D; i++) {
        cout << dp[N].num[i];
    }
}

int main() {
    cin >> N >> K;
    solve();
    return 0;
}

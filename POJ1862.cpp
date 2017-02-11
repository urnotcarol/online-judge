#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip> 
#include <algorithm>
 
using namespace std;

int n;
double w[103];

int main() {
    double res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &w[i]);
    }
    while (n > 0) {   
        if (n == 1) {
            res = w[0];
            break;
        }     
        
        sort(w, w + n);
        double newW = 2 * sqrt(w[n - 1] * w[n - 2]);
        res = newW;
 
        w[n - 2] = newW;
        n--;
    }
    
    cout << setiosflags(ios::fixed) << setprecision(3) << res << endl;
    return 0;
} 

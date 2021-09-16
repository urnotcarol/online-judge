
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int d;
pair<int, int> p[1000];
pair<double, double> r[1000];

double getDx(int py) {
    return (double)sqrt((double)(d * d - py * py));
}

int solve() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        r[i].first = p[i].first - getDx(p[i].second);
        r[i].second = p[i].first + getDx(p[i].second);
    }
    sort(r, r + n);
    int i = 0;
    while (i < n) {
        double rx = r[i].second;
        i++;
        while (i < n && (double)(r[i].first) <= rx) {
            rx = min(rx, r[i].second);
            i++;
        }
        res++;
    }
    return res;
}

int main() {
    int caseNO = 0;
    while(cin >> n >> d && n!= 0) {
        caseNO++;
        int solvable = 1;
        for (int i = 0; i < n; i++) {
            cin >> p[i].first;
            cin >> p[i].second;
            if (p[i].second > d) {
                solvable = 0;
            }
        }
        if (solvable) {
            cout << "Case " << caseNO << ": " << solve() << endl;
        }
        else {
            cout << "Case " << caseNO << ": -1" << endl;
        }   
    }
    return 0;    
}



#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
//cow[100000];
struct Cow {
    int first;
    int second;
    bool operator < (const Cow & c) {
        return first * c.second < second * c.first;
    }
}; 
Cow cow[100000];
typedef long long ll;
//void solve() {
//    int res = 0;
//    
//    while (n > 1) {        
//        int minFlwr = 0x3f3f3f3f;
//        int temp[100000];
//        for (int i = 0; i < n; i++) {  //送第i只奶牛，计算最小会被毁的花数量 
//            int t = cow[i].first;
//            int destroyed = 0;
//            for (int j = 0; j < n; j++) {
//                if (i != j) {
//                    destroyed += cow[j].second;
//                }
//            }
//            temp[i] = 2 * t * destroyed;
//            minFlwr = min(minFlwr, temp[i]);            
//        }
//        res += minFlwr;
//        for (int i = 0; i < n; i++) {
//            if (temp[i] == minFlwr) {
//                swap(cow[n - 1], cow[i]);
//                break;
//            }
//        }
//        n--;
//    }
//    printf("%d", res);
//}

int main() {
    scanf("%d", &n);
    ll sum = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i].first, &cow[i].second);
        sum += cow[i].second;
    }
//    for (int i = 1; i < n; i++) {
//        cout << cow[i].first * cow[i - 1].second << endl;
//        cout << cow[i].second * cow[i - 1].first << endl;
//        if (cow[i].first * cow[i - 1].second < cow[i].second * cow[i - 1].first) {
//            swap(cow[i], cow[i - 1]);
//        }
//    }  //错！！！局部有序！这是排序问题，会受到后面的影响，和酸奶厂那道题不一样！ 
    sort(cow, cow + n);
    for (int i = 0; i < n - 1; i++) {
        sum -= cow[i].second;
        res += 2 * sum * cow[i].first;
    } 
//    printf("%d", res);
    cout << res << endl;
//    solve();
    return 0;
}

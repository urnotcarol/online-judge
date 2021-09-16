#include <iostream>
#include <algorithm>

using namespace std;

int n;
int plank[20000];

void slove() {
    long long res = 0;
    
    while (n > 1) {
        int min = 0;        //最小的板的下标 
        int minNext = 1;    //次小的板的下标 
        
        if (plank[min] > plank[minNext]) {
            swap(min, minNext);
        }
        
        for (int i = 2; i < n; i++) {           //找到最小和次小的两块板 
            if (plank[i] < plank[min]) {
                minNext = min;
                min = i;
            }
            else if (plank[i] < plank[minNext]) {
                minNext = i;
            }
        }
        
        int t = plank[min] + plank[minNext];
        res += t;
                
        if (min == n - 1) {                //将拼合后的板加入到数组中，去掉原来的 
            swap(min, minNext); 
        }
        plank[min] = t;
        plank[minNext] = plank[n - 1];
        
        n--;         
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> plank[i];
    }
    slove();
    
    return 0;    
}

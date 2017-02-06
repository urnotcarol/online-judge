#include <iostream>
#include <algorithm>

using namespace std;

int n;
int plank[20000];

void slove() {
    long long res = 0;
    
    while (n > 1) {
        int min = 0;        //��С�İ���±� 
        int minNext = 1;    //��С�İ���±� 
        
        if (plank[min] > plank[minNext]) {
            swap(min, minNext);
        }
        
        for (int i = 2; i < n; i++) {           //�ҵ���С�ʹ�С������� 
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
                
        if (min == n - 1) {                //��ƴ�Ϻ�İ���뵽�����У�ȥ��ԭ���� 
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

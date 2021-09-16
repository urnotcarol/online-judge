#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_L = 32 + 4;
const int MAX_N = 100 + 4;
const int MAX_Q = 10000 + 4;
int p;
int r;
int u;
int q;

class Privilege {
public:
    string category;
    int level;
    Privilege () {
    }
    Privilege (string input) {
        char tempL = input[input.length() - 1];
        if (tempL <= '9' && tempL >= '0') {
            category = input.substr(0, input.length() - 2);
            level = tempL - '0';
        } 
        else {
            category = input;
            level = -1;
        }
    }
} pri[MAX_N];

struct Role {
    string rolename;
    int s;
    Privilege myPri[MAX_N];
} role[MAX_N];

struct User {
    string username;
    int t;
    string myRole[MAX_N];
} user[MAX_N];

struct Query {
    string username;
    Privilege myPri;
} query[MAX_Q];

int main() {
    scanf("%d", &p);    
    for (int i = 0; i < p; i++) {
        string tempP;
        cin >> tempP;
        Privilege temp(tempP);
        pri[i] = temp;
            
    }
    
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        cin >> role[i].rolename >> role[i].s;
        for (int j = 0; j < role[i].s; j++) {
            string tempP;
            cin >> tempP;
            Privilege temp(tempP);
            role[i].myPri[j] = temp;     
        }
    }
    
    scanf("%d", &u);
    for (int i = 0; i < u; i++) {
        cin >> user[i].username >> user[i].t;
        for (int j = 0; j < user[i].t; j++) {
            cin >> user[i].myRole[j];
        }
    }
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        string tempP;
        cin >> query[i].username >> tempP;
        Privilege temp(tempP);
        query[i].myPri = temp;
        bool validUser = false;
        bool validPri = false;
        bool done = false;
        for (int j = 0; j < u; j++) {
            if (user[j].username == query[i].username) {
                validUser = true;
                int maxLevel = -1;
                for (int k = 0; k < user[j].t; k++) {
                    if (done) {
                        break;
                    }                    
                    for (int x = 0; x < r; x++) {
                        if (role[x].rolename == user[j].myRole[k]) {
                            for (int y = 0; y < role[x].s; y++) {
                                if (role[x].myPri[y].category == query[i].myPri.category) {             
                                    validPri = true;                       
                                    if (role[x].myPri[y].level == -1) {  
                                        cout << "true" << endl;
                                        done = true;
                                        break;
                                    }
                                    else if (role[x].myPri[y].level > -1) {
                                        maxLevel = max(maxLevel, role[x].myPri[y].level);
                                    }
                                }
                            }
                        }
                    }
                }
                if (!done && validPri) {
                    if (query[i].myPri.level == -1) {
                        cout << maxLevel << endl;
                    }
                    else if (query[i].myPri.level <= maxLevel) {
                        cout << "true" << endl;
                    }
                    else {
                        cout << "false" << endl;
                    }
                }
            }
        }    
        if (!validUser || !validPri) {
            cout << "false" << endl;
        }    
    }    
    return 0;
} 

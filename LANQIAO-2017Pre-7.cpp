#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>

using namespace std;

const int MAX_N = 100 + 16;
char a[MAX_N];
char b[2 * MAX_N];
typedef pair<char, int> P;

char precede(char op1, char op2) {
    map<char, int> opIndex;
    opIndex.insert(P('*', 0));
    opIndex.insert(P('|', 1));
    opIndex.insert(P('(', 2));
    opIndex.insert(P(')', 3));
    opIndex.insert(P('#', 4));
    char pri[5][6] = {
        {'>', '>', '<', '>', '>'},
        {'<', '>', '<', '>', '>'},
        {'<', '<', '<', '=', '0'},
        {'>', '>', '0', '>', '>'},
        {'<', '<', '<', '0', '='}
    };
    int x = (opIndex.find(op1))->second;
    int y = (opIndex.find(op2))->second;
    return pri[x][y];    
}

int operate(int a, char op, int b) {
    int res;
    if (op == '*') {
        res = a + b;
    }
    else if (op == '|') {
        res = max(a, b);
    }
    return res;
}

int evaluateExpression() {
    stack<char> optr;
    optr.push('#');
    stack<int> opnd;
    int i = 0;
    while (b[i] != '#' || optr.top() != '#') {
        char c = b[i];
        if (c == 'x') {
            opnd.push(1);
            i++;
        }
        else {
            switch(precede(optr.top(), c)) {
            case '<':
                optr.push(c);
                i++;
                break;
            case '>': {
                char op = optr.top();
                optr.pop();
                int y = opnd.top();
                opnd.pop();
                int x = opnd.top();
                opnd.pop();
                opnd.push(operate(x, op, y));
                break;
            }
            case '=':
                optr.pop();
                i++;
                break;                    
            }
        }
    }
    return opnd.top();
}

int main() {
    scanf("%s", a);
    int len = strlen(a);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if ((a[i] == 'x' && a[i + 1] == 'x') 
            || (a[i] == ')' && a[i + 1] == 'x')
            || (a[i] == ')' && a[i + 1] == '(')) {
            b[count] = a[i];
            count++;
            b[count] = '*';
            count++;
            b[count] = a[i + 1];
        }
        else {
            b[count] = a[i];
            count++;
        }
    }
    len = strlen(b);
    b[len] = '#';
    printf("%d", evaluateExpression());
    return 0;
} 

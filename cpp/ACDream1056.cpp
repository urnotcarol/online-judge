#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int MAX_M = 100 + 4; 
int T;
int M;
struct Member {
    string name;
    vector<string> edge;
    int color;
};
vector<Member> member;

void init(string node1, string node2) {
    bool found = false;
    for (int j = 0; j < member.size(); j++) {
        if (member[j].name == node1) {
            member[j].edge.push_back(node2);
            found = true;
            break;
        }
    }
    if (!found) {
        Member temp;
        temp.name = node1;
        temp.edge.push_back(node2);
        temp.color = 0;
        member.push_back(temp);
    }
}

bool dfs(int v, int c) {
    member[v].color = c;
    int index;
    for (int i = 0; i < member[v].edge.size(); i++) {
        for (int j = 0; j < member.size(); j++) {
            if (member[j].name == member[v].edge[i]) {
                index = j;
                break;
            }
        }
        if (member[index].color == c) {
            return false;
        }
        if (member[index].color == 0 && !dfs(index, -c)) {
            return false;
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < member.size(); i++) {
        if (member[i].color == 0) {
            if (!dfs(i, 1)) {
                return false;
            }
        }
    } 
    return true;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        bool res;
        scanf("%d", &M);
        for (int i = 0; i < member.size(); i++) {
            member[i].edge.clear();
        }
        member.clear();
        string first;
        string second;
        for (int i = 0; i < M; i++) {
            cin >> first >> second;
            init(first, second);
            init(second, first);
        }
   
        if (solve()) {
            printf("Case #%d: Yes\n", t);
        }    
        else {
            printf("Case #%d: No\n", t);
        }
    }
    return 0;
}

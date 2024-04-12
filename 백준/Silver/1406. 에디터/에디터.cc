#include <bits/stdc++.h>
using namespace std;

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    string s;
    cin >> s;
    list<char> L;

    for (int i = 0; i < s.size(); i++) {
        L.push_back(s[i]);
    }

    list<char>::iterator cursor = L.end(); //end의 인덱스를 가르킨다.

    int q;
    cin >>q;
    while(q--) {
        char op; cin >>op;

        if (op == 'P') {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op == 'L') {
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') {
            if (cursor != L.end()) cursor++;
        }
        else { // 'B'
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }


    for (char i: L) cout << i;
}


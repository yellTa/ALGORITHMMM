#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    string answer;
    while(1) {
        string s; getline(cin,s);
        stack<char> st;
        bool flag = true;
        if(s[0] =='.') break;

        for(auto c: s) {
            if(c == '(' || c== '[') {
                st.push(c);
            }else if(c ==')') {
                if(st.empty() || st.top() !='(') {
                    flag =false;
                    break;
                }
                st.pop();
            }else if(c == ']') {
                if(st.empty() || st.top() !='[') {
                    flag =false;
                    break;
                }
                st.pop();
            }
        }

        if(!st.empty()) flag = false;

        if(flag) cout << "yes \n";
        else cout << "no \n";
    }


    cout << answer;
}

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

        if(s[0] =='.') {
            break;
        }

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }else if(s[i] == '[') {
                st.push(s[i]);
            }

            if(s[i] == ')') {
                if( !st.empty() && st.top() == '(') {
                    st.pop();
                }else st.push(s[i]);
            }else if(s[i] == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                }else st.push(s[i]);
            }

        }
        
        if(st.size() ==0) {
            answer += "yes \n";
        }else {
            answer +="no \n";
        }


    }
    cout << answer;
}

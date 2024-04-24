#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int MA = 0;
int tempA = 0;
int answer = 0;

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);

    int tc; cin >> tc;

    cin.ignore();
    while(tc--){
        string s; getline(cin, s);

        stack<char> st;
        string answer="";

        for(int i=0; i< s.size()+1; i++) {
            if(s[i] == ' ' || i==s.size()) {
                while(!st.empty()) {
                    answer += st.top();
                    st.pop();
                }
                answer += " ";
            }else st.push(s[i]);
            if(i == s.size())break;
        }
        cout << answer <<"\n";
    }
}

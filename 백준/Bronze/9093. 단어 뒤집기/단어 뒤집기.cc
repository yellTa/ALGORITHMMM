#include <iostream>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>

#define X first //세로
#define Y second //가로

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int tc ; cin>>tc;

    stack<char> stack;
    cin.ignore();
    while(tc--) {
        string s; getline(cin,s);
        string answer="";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != ' ') {
                stack.push(s[i]);

            }else if(s[i] == ' '){
                while(!stack.empty()) {
                    answer += stack.top(); stack.pop();
                }
                answer += " ";
            }
        }
        while(!stack.empty()) {
         answer += stack.top(); stack.pop();
        }

        cout << answer;
        cout << "\n";
    }





}

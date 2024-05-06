#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    string s; cin >>s;

    stack<int> stack;
    int answer =0;
    int temp=1;
    bool flag=true;
    for(int i=0; i< s.size(); i++) {
        if(s[i] == '(') {
            flag = true;
            stack.push('(');
            temp *=2;
        }

        if(s[i] == '[') {
            flag = true;
            stack.push('[');
            temp *=3;
        }

        if(s[i] == ')' || s[i] == ']') {
            if(stack.empty()) {
                cout << 0;
                return 0;
            }
            if(s[i] == ')' && stack.top()== '(') {
                stack.pop();

                if(flag)answer += temp;
                temp /=2;
                flag = false;
                continue;
            }
            if(s[i] == ']' && stack.top()== '[') {
                stack.pop();
                if(flag)answer +=temp;
                temp /=3;
                flag = false;
                continue;
            }
            cout << 0; return 0;

        }
    }
    if(stack.empty())    cout <<answer;
    else cout << 0;

}

#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);



    string s; cin >>s;


    stack<int> stack;
    queue<char> queue;

    for(int i=0; i< s.size(); i++) {
        if(s[i] >= '0' && s[i] <='9') {
            stack.push(s[i]-'0');
        }else {
            int b,c;
            c= stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();

            if(s[i] =='+') {
                stack.push(b+c);
            }else if(s[i] =='*') {
                stack.push(b*c);
            }else if(s[i] =='-') {
                stack.push(b-c);
            }else if(s[i] == '/') {
                stack.push(b/c);
            }

        }
    }
    cout << stack.top();
}

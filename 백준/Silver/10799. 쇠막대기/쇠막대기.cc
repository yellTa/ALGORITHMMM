#include <stack>
#include <iostream>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    string n;
    cin >> n;

    stack<char> O;
    int answer = 0;
    for (int i = 0; i < n.size(); i++) {
        char c = n[i];

        if (c == '(') O.push(c);
        else if (!O.empty()){
           if(i>0 && O.top() == '(' && n[i] ==')') {
               if(n[i-1] =='(') {//레이저
                   O.pop();
                   answer +=O.size();
               }else {//닫기
                   answer +=1;
                   O.pop();

               }
           }
        }
    }

    cout << answer;
}

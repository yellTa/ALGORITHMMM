#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

   int tc; cin >> tc;

    deque<int>dq;
    string answer="";
    while(tc--) {
        string cmd; cin >> cmd;

        if(cmd == "push") {
            int i; cin >>i;
            dq.push_back(i);
        }else if(cmd == "pop") {
            if(!dq.empty()) {
                int x =dq.front();
                answer +=to_string(x)+"\n";
                dq.pop_front();
            }else  answer += "-1 \n";
        }else if(cmd == "size") {
            answer += to_string(dq.size()) +"\n";
        }else if(cmd == "empty") {
            if(dq.empty())answer +="1 \n";
            else answer +="0 \n";
        }else if(cmd == "front") {
            if(!dq.empty()) {
                answer += to_string(dq.front())+ "\n";
            }else answer += "-1 \n";
        }else if(cmd == "back") {
            if(!dq.empty()) {
                answer += to_string(dq.back())+ "\n";
            }else answer += "-1 \n";
        }

    }

    cout << answer;

}

#include<map>
#include<algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int m; cin>>m;

    queue<int> q;
    for(int i=0; i<n; i++) {
       q.push(i+1);
    }
    int index=0;
    int B[n]={};

    cout << "<";
    while(q.size()!=1) {

        for(int k=0; k<m-1; k++) {
            int t= q.front();
            q.push(t);
            q.pop();
        }
        cout << q.front() <<", ";
        q.pop();
    }

    cout << q.front() << ">";


}
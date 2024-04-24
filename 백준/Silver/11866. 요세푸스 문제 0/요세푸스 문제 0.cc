#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int MA = 0;
int tempA = 0;
int answer = 0;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,k; cin >> n  >>k;

    int A[n];
    queue<int> q;

    int index=0;
    for(int i=0; i<n; i++) {
        q.push(i+1);
    }

    for(int i=0; i<n; i++) {
        while(index != k-1) {
            q.push(q.front());
            q.pop();

            index +=1;
        }
        index =0;
        A[i] = q.front();
        q.pop();
    }

    cout << "<";
    for(int i=0; i<n-1; i++) {
        cout << A[i] <<", ";
    }
    cout << A[n-1] <<">";
}

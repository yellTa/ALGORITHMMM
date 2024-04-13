# include<iostream>

using namespace std;

int main(void) {
    int n; cin>>n;

    int A[n]={};

    for(int i=0; i<n; i++) {
        cin >>A[i];
    }


    int stick = A[n-1];
    int cnt =1;

    for(int i=n-2; i>=0; i--) {
        if(A[i] > stick) {
            cnt++;
            stick = A[i];
        }

    }
    cout << cnt;

}
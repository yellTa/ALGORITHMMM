#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int value[25];
int a, b;

void swapCard(int a, int b){
    for(int i=0; i<((b-a)/2) +1; i++) {
        swap(value[a+i],value[b-i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int 배열 만들기
    for(int i=1; i<=20; i++)value[i]=i;

    for(int i=0; i<10; i++) {
        cin >>a; cin >>b;
        swapCard(a,b);
    }

    for(int i=1; i<21; i++)cout << value[i]<< " ";

}

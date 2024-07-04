#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int num ; cin >> num;

    int newCycle=num-1;
    for(int i=1 ; i<= 2*num -1; i++) {
        if(i<=num) {
            for(int lStar = 0; lStar<i; lStar++) cout << "*";
            for(int space = 2*(num-i); space >0; space--)cout << " ";
            for(int rStar=0; rStar<i; rStar++)cout << "*";

        }else {
            for(int lStar = 0; lStar<newCycle; lStar++) cout << "*";
            for(int space = 2*(num-newCycle); space >0; space--)cout << " ";
            for(int rStar=0; rStar<newCycle; rStar++)cout << "*";
            newCycle--;
        }

        cout << "\n";


    }



}

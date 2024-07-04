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

    int max= -1;
    int position=0;
    for(int i=0 ; i<9; i++) {
        int x; cin>>x;
        if(x>max) {
            max = x;
            position =i+1;
        }
    }

    cout << max<< "\n";
    cout << position;




}

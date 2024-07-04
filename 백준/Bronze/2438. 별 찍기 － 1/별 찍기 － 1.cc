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

  for(int i=1 ; i<= num ;i++){
    for(int k=0; k<i; k++) {
      cout << "*";
    }
    cout << "\n";
  }

}

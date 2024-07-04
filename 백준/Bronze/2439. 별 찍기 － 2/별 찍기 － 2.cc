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
    for(int space=0; space < num-i; space++)cout << " ";
    for(int star=0; star<i; star++)cout << "*";
    cout << "\n";

  }

}

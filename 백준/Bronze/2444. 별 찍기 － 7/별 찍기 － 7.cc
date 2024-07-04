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

  int cycle=1;
  for(int i=1; i<= num*2-1 ;i++){
    if(i<num+1) {
      for(int space =num -i; space>0; space--)cout << " ";
      for(int star = 2*i-1; star>0; star--)cout << "*";
    }else {
      for(int space =0; space<cycle; space++)cout << " ";
      for(int star=2*(num-cycle)-1; star>0; star--)cout << "*";
      cycle++;
    }
    cout <<"\n";

  }

}

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

vector<int> store(21);

void reverse(int x, int y) {
    for(int i=0; i<((y-x+1)/2);  i++) {
        swap(store[x+i], store[y-i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i=1; i<=20; i++) {
        store[i] = i;
    }

    for(int i=0; i<10; i++) {
        int x,y; cin >> x>>y;

        reverse(x,y);
    }

    for(int i=1; i<21; i++)cout << store[i] << " ";

}

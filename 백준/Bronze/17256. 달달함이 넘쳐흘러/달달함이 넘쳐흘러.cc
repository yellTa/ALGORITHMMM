#include <stack>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int ax,ay,az; cin >> ax>>ay>>az;
    int cx, cy,cz; cin >> cx >> cy >> cz;

    cout << cx-az <<" "<< cy/ay <<" "<< cz-ax;

}


#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

//c 문자종류
//l 비밀번호 자릿수
int l,c;

char words[20];
int isused[20];
int arr[20];

void func(int k) {
    if(k==l) {
        // 자음 모음 체크 로직
        int m=0; int j=0;
        string s;

        for(int i=0; i<l; i++) {
            char c = words[arr[i]];
            s += c;
            if(c =='a' || c =='e' ||c =='i' || c == 'o'|| c =='u') {
                m++;
            }else j++;
        }

        if(m>0 && j>1)cout <<s<< "\n";

        return;
    }

    int st=0;
    if(k!=0) st= arr[k-1]+1;

    for(int i=st; i<c; i++) {
        if(!isused[i]) {
            isused[i] =1;
            arr[k] = i;

            func(k+1);
            isused[i] =0;
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l>>c;

    for(int i=0; i< c; i++) {
        cin >> words[i];
    }
    sort(words, words+c);

    func(0);


}

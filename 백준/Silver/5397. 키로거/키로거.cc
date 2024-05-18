#include <queue>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
/*
*[문제의 조건]
* 입력: 알파벳 대소문자, 숫저 - (backsapce), 화살표 <<>>
*
* [문제의 입력]
*  1. tc
*  2. L (1 <= 10^6)
*  - : 바로앞에 글자 존재하면 지우기
*  화살표 의 입력 : <> 왼쪽 +1 , 오른쪽 +1
*
*
* [IDEA]
* 연결 리스트를 사용하면 좋을 듯
* 커서의 위치를 p라고 지정
*
* 1. 문자가 들어오는 경우 - 넣고 iterator +1
* 2. 화살표가 들어오는 경우
* < iterator -1 대신에 iter는 begin()이 아님
*  > iterator +1 대신 iter는 end()가 아님
*
* 3. 백스페이스가 들어오는 경우
* iter --
* 후에 list에서 제거
*
*
*
* */
using namespace std;

int t;
string s;
int main()
{
    cin >> t;

    while (t--)
    {
        list<char> l;
        list<char>::iterator it = l.end();

        cin >> s;

        for (char str : s)
        {
            if (str == '<')
            {
                if (it != l.begin()) it--;
            }
            else if (str == '>')
            {
                if (it != l.end()) it++;
            }
            else if (str == '-')
            {
                if (it != l.begin()) l.erase(prev(it));
            }
            else
                l.insert(it, str);
        }

        for (char str : l)
        {
            cout << str;
        }
        cout << '\n';
    }
}

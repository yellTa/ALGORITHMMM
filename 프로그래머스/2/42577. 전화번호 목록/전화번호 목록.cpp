#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
 *[문제]
 * 접두어 전화번호가 존재하면 false 존재하지 않으면 true
 * 전화번호부가 담긴 phonebook 거기서 어떤 번호가 다른 번호의 접두어  - false
 * 접두어가 아님 true
 *
 *중복해서 들어있는 경우는 없다.
 *
 * [입력]
 * 전화번호부에 적힌 전화번호를 담은 배열 phone_book
 *
 * phone_book의 길이 1<= x <=10^7
 * 1<= 전화번호 길이 <=20
 *
 *
 * [출력]
 *  전화번호부가 담긴 phonebook에서 접두어를 찾음 -false
 *  아니면 true반환
 *
 * [IDEA]
 * 모든 경우의 수를 전부 다 돌아야한다. 이중 for문을 사용해서 모두 돌리도록 하자
 *
 * A가 접두어 B,C가 phonebook의 전화번호라고 하면 false가 나오려면 B나 C가
 * A의 길이 이상이어야하고 0,A.size까지의 값이 A와 동일해야한다.
 * 하나라도 찾으면 로직을 종료하고 false를 리턴한다.
 *
 *
 * [psudo code]
 *  answer = false //정답의 default값을 false로 지정
    phone_book을 sorting 수행
 *  이중 for문으로 데이터 검사
 *        - 접두어 A, 검사 단어 B
 *        - 검사단어 B의 0,size의 값이 A와 같나?
 *           true출력 로직 종료
 *
 * answer출력
 */

/*
효율문제를 해결하기 위한 방안
1. phone_book을 사전순으로 정리한 후 인접한 인덱스끼리만 검사
위의 방법은 phone_book의 요소가 int가 아닌 string이라서 가능하다.O(n)에 끝낼 수 있다.

2. hash를 사용하는 방법

*/
bool solution(vector<string> phone_book) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    bool answer = true;
    unordered_map<string ,int> hash_map;
    
    for(int i=0; i< phone_book.size(); i++){
        hash_map[phone_book[i]] =1; // key를 String으로 두었다.
        
    }
    
    for(int i=0; i< phone_book.size(); i++){
        string phone_number = "";
        for(int j=0; j< phone_book[i].size(); j++){
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])//phone_number != phone_book은 동일한 컨텐츠를 제외해야하므로 
                return false;
        }
    }
    
    return answer;
}
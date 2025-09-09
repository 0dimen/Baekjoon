/*
    10816 숫자 카드 2 : https://www.acmicpc.net/problem/10816

    문제
        - N : 상근이가 가진 숫자 카드 개수
        - M : 개수를 알고 싶은 숫자 카드의 수
    
    문제 풀이
        - 풀이 1. 카드의 숫자를 int 배열에 저장.
        - 풀이 2. map을 통해 (시도 X)
            - 장점 : 메모리 사용이 적음
            - 단점 : 상근이가 가진 카드를 입력받을 때, 매번 카드 존재 여부를 확인해야 하여 비효율적.
*/

#include <iostream>
using namespace std;

#define ZEROPOINT 10000000

int cardsNum[20000001] = {0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    for (int n = 0; n < N; n++){
        int card;
        cin >> card;
        cardsNum[ZEROPOINT + card]++;
    }

    cin >> M;

    for(int m = 0; m < M; m++){
        int card;
        cin >> card;
        cout << cardsNum[ZEROPOINT + card] << " ";
    }

    return 0;
}
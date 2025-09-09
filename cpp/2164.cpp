/*
    2164번 카드2 : https://www.acmicpc.net/problem/2164
    
    문제
        - N : 카드 번호
        - 순서
            1. 제일 위에 카드 버림
            2. 제일 위 카드를 제일 아래로 옮김
        - 마지막 카드 번호 출력
    문제 풀이
        - queue 형태의 카드 순서. (FIFO)
        - 복잡도 : O(n);
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;

    queue<int> cards;
    for(int i = 1; i <= N; i++){
        cards.push(i);
    }

    while(cards.size() >1){
        cards.pop();
        int top = cards.front();
        cards.pop();
        cards.push(top);
    }
    cout << cards.front();
    return 0;
}

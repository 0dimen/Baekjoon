/*
    1074 Z : https://www.acmicpc.net/problem/1074

    문제
        - N : 2^N의 N
        - r : 행
        - c : 열
    
    문제 풀이
        - 4분할로 나누며 위치를 추적.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N, r, c;

    cin >> N >> r >> c;
    int squaredNum = pow(2,N);
    int turn = 0;
    while(squaredNum>=2){
        int remainR = 0; // 나머지
        squaredNum /=2;
        int unitNum = squaredNum*squaredNum;
        if(squaredNum <= c){ // 2,4 사분면에 있는 경우
            remainR = 1;
        }

        if(squaredNum <= r){ // 3, 4 사분면에 있는 경우
            turn += unitNum*2 + remainR*unitNum;
        }
        else{
            turn += remainR*unitNum;
        }
        r%=squaredNum;
        c%=squaredNum;
    }
    cout << turn;

    return 0;
}
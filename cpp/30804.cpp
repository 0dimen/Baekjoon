/*
    30804번 탕후루 : https://www.acmicpc.net/problem/30804

    문제
        - N : 과일의 개수
        - S_n : 탕후루에 꽂힌 과일
        - 2가지 종류의 숫자로만 이루어진 배열의 최대 길이

*/

#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int max = 0;
    int totalCount = 1;
    int currentNumCount = 0;
    int currentNum = -1;
    int firstNum = -1;
    for (int s = 0; s<N; s++){
        int S;
        cin >> S;

        if(currentNum == S){ // 바로 전과 같은 과일인 경우
            currentNumCount++;
            continue;
        }

        // 다른 과일인 경우
        totalCount += currentNumCount;

        if(firstNum != S){ // 종류가 2개를 초과하는 경우.
            if(max<totalCount){
                max = totalCount;
            }
            totalCount = currentNumCount;
        }

        // firstNum, currentNum 변경.
        currentNumCount = 1;
        firstNum = currentNum;
        currentNum = S;
    }

    totalCount+= currentNumCount;
    if(max < totalCount){
        max=totalCount;
    }

    cout << max;

    return 0;
}
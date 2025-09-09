// 10799번 쇠막대기 : https://www.acmicpc.net/problem/10799

/*
문제 : "()"는 레이저. 레이저를 감싸는 "(...)"는 쇠막대기 레이저로 잘린 쇠막대기 숫자를 구하라

풀이
    
    - case. laser
        - '(' 다음 바로 ')'가 오면 레이저로 판단. 이외는 모두 쇠막대기.
        - 막대기가 있다면, 레이저가 막대기를 자르므로, 쌓여있는 막대기의 숫자를 더한다.
    - case. bar
        - open : '('는 막대기의 시작을 의미한다.
        - close : ')'는 막대기의 끝을 의미하므로, 말단 막대기 개수를 1 추가한다.
            - 막대기 사이에는 반드시 레이저가 있으므로, 각각의 막대기는 반드시 말단 막대기를 가지고 있다.
        

*/

#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;

    int barNum = 0; // bar number
    int result = 0;
    for(int i = 0; i<input.length(); i++){
        if(input[i]=='('){
            if(input[i+1]==')'){ // case. laser
                result += barNum;
                i++; // change to next index
            }
            else // case. bar open
                barNum++;
        }
        else{ // case. bar close
            barNum--;
            result++;
        }
    }
        
    cout << result;
    return 0;
}
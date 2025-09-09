// 23304번 아카라카 : https://www.acmicpc.net/problem/23304
/*
풀이 방법 : 재귀 함수.

배운 점
    - substr(n1,n2) 함수는 n1~ (n2-1)까지 글자를 자른다.
*/

#include <iostream>
#include <string>
using namespace std;
bool isAKA = true;

void f1(string input){
    if(!isAKA)
        return;
    int maxIndex = input.length()-1;
    

    for(int i = 0; i<(int)maxIndex/2; i++){
        if(input[i]!=input[maxIndex-i]){
            isAKA = false;
            break;
        }
    }
    if(isAKA){ // S/2로 나누어 재귀함수 호출. AKARAKA인지 확인.
        if(maxIndex <= 1) // 길이가 2 이하일 경우, 더 나눌 필요 없음.
            return;
       
        if((maxIndex+1)%2==0) // S의 길이가 짝수인 경우 
            f1(input.substr(0, (int)maxIndex/2+1));
        else // S의 길이가 홀수인 경우, 중앙의 글자를 제외한다.
            f1(input.substr(0, (int)maxIndex/2));
        
        

        f1(input.substr(((int)maxIndex)/2+1, maxIndex+1));
    }
    
}

int main(){
    string input;
    cin >> input;
    
    f1(input); // 재귀함수 호출

    if(isAKA)
        cout << "AKARAKA";
    else
        cout << "IPSELENTI";

    return 0;
}
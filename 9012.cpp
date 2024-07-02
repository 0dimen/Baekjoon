/*
    9012번 괄호 : https://www.acmicpc.net/problem/9012

    문제
        - VPS : ()가 올바른 쌍을 이룸.
        - 쌍을 이룬다
            - 열린 괄호가 누적되고, 닫힌 괄호가 열린 괄호 갯수를 상쇄시키는 것.
            - 단, 닫힌 괄호가 선행될 수는 없으므로, 열린 괄호의 개수가 1 미만일 시, VPS가 아니다.
            - 모든 과정을 거치고 난 후, 열려있는 괄호가 0개일 시 VPS, 아닐 시 VPS가 아니다.
*/

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t = 0; t<T; t++){
        string input;
        cin >> input;
        int openNum = 0;
        string result = "YES";
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '('){
                openNum++;
            }
            else{ // ')'인 경우
                if(openNum < 1){ // 닫을 괄호가 없는 경우
                    result = "NO";
                    break;
                }
                else{
                    openNum--;
                }
            }
        }

        if(openNum != 0){
            result = "NO";
        }

        cout << result << "\n";
    }

    return 0;
}
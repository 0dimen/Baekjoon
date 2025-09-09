/*
    11723 집합 : https://www.acmicpc.net/problem/11723

    - 문제 풀이
        - 중복되는 값이 없는 배열을 구현. -> set를 통해 구현.
        - 최적화
            - 문제 상황 : 공백 구분을 위해서 getline과 stringstream을 사용. 그러나 이 방식이 시간이 오래 걸렸음.
            - 해결 방법 : 단순히 cin을 통해서 공백 구분이 가능하다는 것을 알게됨.
*/

#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

void commandFunction(string command, set<int>& S){
    if(command == "all"){
        for(int i = 1; i<21; i++){
            S.insert(i);
        }
        
    }
    else if(command == "empty"){
        set<int> newS;

        S = newS;
    }
    else{
        int num;
        cin >> num;
        if(command == "add"){
            S.insert(num);
        }
        else if(command == "remove"){
            S.erase(num);
        }
        else if(command == "check"){
            if(S.find(num) != S.end()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(command == "toggle"){
            if(S.find(num) != S.end()){
                S.erase(num);
            }else{
                S.insert(num);
            };
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> S;
    int M;
    cin >> M;

    string input;
    for (int i =0; i< M; i++){
        
        cin >> input;
        commandFunction(input, S);
    }
    
    return 0;
}


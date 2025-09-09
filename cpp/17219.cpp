/*
    17219 비밀번호 찾기 : https://www.acmicpc.net/problem/17219
    
    문제
        - N : 저장된 사이트 주소 수
        - M : 찾으려는 사이트 주소 수
        - input : 사이트 비밀번호
    
    문제 풀이
        - 
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> password;

    int N, M;
    cin >> N >> M;

    for(int i = 0; i< N; i++){
        string url, pw;

        cin >> url >> pw;
        password[url] = pw;
    }

    for(int i = 0; i< M; i++){
        string url;
        cin >> url;
        cout << password.at(url) << '\n';
    }


    return 0 ;
}
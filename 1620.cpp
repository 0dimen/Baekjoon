/*
    1620 나는야 포켓몬 마스터 이다솜 : https://www.acmicpc.net/problem/1620

    문제
        - N : 도감에 등록된 포켓몬의 개수
        - M : 문제의 개수
        - 도감에 등록된 포켓몬의 이름을 대조하여 포켓몬 번호를 출력.
    문제 풀이 :
        - map 사용
            - key 값(포켓몬 이름)을 통해 바로 포켓몬 번호에 접근
        - vector 사용
            - 포켓몬 번호(인덱스 값)을 통해 포켓몬 이름에 접근
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    map<string, int> PokedexName;
    vector<string> PokedexNumber;

    for(int i = 1; i<=N ; i++){
        string pokemon;
        cin >> pokemon;
        PokedexName.insert(pair<string, int>(pokemon, i));
        PokedexNumber.push_back(pokemon);
    }

    for(int i = 0; i< M; i++){
        string input;
        cin >> input;
        if(isdigit(input[0])){ // 도감 번호를 입력한 경우
            cout << PokedexNumber[stoi(input)-1] << "\n";
        }
        else{ // 포켓몬 이름을 이볅한 경우
            cout << PokedexName[input] << "\n";
        }
    }

    return 0;
}

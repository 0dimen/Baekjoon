/*
    21736번: 헌내기는 친구가 필요해 : https://www.acmicpc.net/problem/21736

    문제 풀이
    - 도연과 친구가 도연이 속해있는 닫힌 계에 존재해야한다.

    
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int dx, dy; // 도연 위치


    // map의 I : 도연 위치, O : 친구 위치, X : 벽, V : 방문한 위치
    vector<vector <char> > map;
    // map 입력받기.
    for(int n = 0; n < N; n++){
        char input;
        vector<char> row;
        for(int m = 0; m < M; m++){
            cin >> input;
            if(input == 'I'){
                dx = n;
                dy = m;
                input = 'V';
            }
        }
        map.push_back(row);
    }
    int count = 0;
    vector< pair <int, int> > nextPath = {{dx, dy}};
    // 도연 위치에서 이동.
    while(!nextPath.empty()){
        int x = nextPath.back().first;
        int y = nextPath.back().second;

        // 범위를 벗어나는 경우 다음 경로로 넘어감.
        if(x < 1 || x > 600 || y < 1 || y > 600){
            nextPath.pop_back();
            continue;
        }
        
        switch(map[x][y]){
            case 'V':
                {continue;}
            case 'X':
                continue;
            case 'P':
            {
                map[x][y] = 'V';
                count++;
                break;
            }
            case 'O':
            {
                map[x][y] = 'V';
                break;
            }
        }

        
        nextPath.pop_back();
        // 상하좌우 넣기.
        nextPath.push_back({dx + 1, dy});
        nextPath.push_back({dx - 1, dy});
        nextPath.push_back({dx, dy + 1});
        nextPath.push_back({dx, dy - 1});

            
    }


    return 0;
}
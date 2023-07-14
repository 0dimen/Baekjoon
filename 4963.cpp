// 4963 섬의 개수 https://www.acmicpc.net/problem/4963
/*
- 문제 : w*h의 2차원 지도가 있다. 지도는 0(바다), 1(땅)으로 이루어져있다. 섬의 개수를 구하라.
    - 섬 : 가로, 세로, 대각선으로 연결된 땅은 하나의 섬으로 취급한다.

- 풀이
    - 가정 : bfs를 통해 하나의 섬에 대해 연결된 땅을 모두 찾았다고 가정.
        - 탐색을 완료한 땅은 false로 변경하여 재탐색하지 않게 함.
*/
#include <iostream>
#include <vector>
using namespace std;

int landNum; // 섬 개수
int w;
int h;
 
void bfs(vector<vector <bool> > &map, int y, int x){
    if(!map[y][x]) // 탐색한 경우 or 바다인 경우
        return;
    if(map[y][x] == true){
        map[y][x] = false;

        if(x > 0){
            if(map[y][x-1])
                bfs(map, y, x-1);
            if(y > 0){
                if(map[y-1][x-1])
                    bfs(map, y-1, x-1);
            }
            if(y < h-1){
                if(map[y+1][x-1])
                    bfs(map, y+1, x-1);
            }
        }
        if(x < w-1){
            if(map[y][x+1])
                bfs(map, y, x+1);
            
            if(y > 0){
                if(map[y-1][ x+1])
                    bfs(map,y-1, x+1);
            }
            if(y < h-1){
                if(map[y+1][x+1])
                    bfs(map, y+1, x+1);
            }
            
        }
        if(y > 0){
            if(map[y-1][x])
                bfs(map, y-1, x);
        }
        if(y < h-1){
            if(map[y+1][x])
                bfs(map, y+1, x);
        }
    }
    
}

int main(){
    cin >> w >> h;
    while(w != 0 && h != 0){
        landNum = 0;
        vector<vector <bool> > map; // 0 : 바다, 1 : 땅
        
        // map 입력받음
        for(int j = 0; j < h; j++){
            vector<bool> inputLine;
            for(int i = 0; i<w; i++){
                bool isLand;
                cin >> isLand;
                
                inputLine.push_back(isLand);
            }
            map.push_back(inputLine);
        }
        
        for(int j=0; j < h; j++){
            for(int i=0; i < w; i++){
                if (map[j][i]){
                    landNum++;
                    bfs(map, j, i);
                }
            }
        }

        cout << landNum << "\n";

        cin >> w >> h;
    }
    return 0;
}

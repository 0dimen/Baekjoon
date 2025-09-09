/*
    1012 유기농 배추 : https://www.acmicpc.net/problem/1012

    문제
        - T : 테스트 케이스 개수
        - M, N : 배추밭 가로, 세로
        - K : 배추가 심어진 위치의 개수
        - X, Y : 배추의 위치
        - 연결되어 있는 배추 그룹의 개수를 출력.
    문제 풀이
        - 연결되어 있는 배추 그룹의 개수를 구하기
        - 전체 맵에서 BPS 탐색을 통해, 그룹의 개수 구함.
            - 특정 좌표 사방에 1로 표시된 좌표가 있으면, 해당 좌표를 stack에 넣음.
            - 이미 지난 좌표는 0으로 표시하여, 이후 전체 맵 탐색 시, 재탐색 되는 것을 막음.
*/

#include <iostream>
using namespace std;
#define MAX 51

void BPS(bool (&land)[MAX][MAX], int x, int y){
    land[y][x] = false;
    // 상
    if(y > 0){
        if(land[y-1][x] == true){
            BPS(land, x, y-1);
        }
    }
    // 하
    if(y < 49){
        if(land[y+1][x]== true)
            BPS(land, x, y+1);
    }
    // 좌
    if(x > 0){
        if(land[y][x-1]== true)
            BPS(land, x-1, y);
    }
    // 우
    if(x < 49){
        if(land[y][x+1]== true)
            BPS(land, x+1, y);
    }
}

void testCase(){
    // 밭 초기화
    bool land[51][51];
    for(int i = 0; i <= 50; i++){
        for(int j = 0; j<= 50; j++){
            land[i][j] = false;
        }
    }

    int M , N, K;
    cin >> M >> N >> K;
    int result = 0;
    for(int k = 0; k < K; k++){
        int X, Y;
        cin >> X >> Y;
        land[Y][X] = true;
    }

    for(int n = 0; n<N;n++){
        for(int m = 0; m < M; m++){
            if(land[n][m] == true){
                result++;
                BPS(land, m, n);
            }
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        testCase();
    }

    return 0;
}
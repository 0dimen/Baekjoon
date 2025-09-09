// 2178 https://www.acmicpc.net/problem/2178

// BFS를 통해 풀이.
// 다음 경로가 최솟값을 가질때에만 이동.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector< vector<int > > miro;

    for(int n = 0; n < N; n++){ // miro map 입력받기.
        vector<int> row;
        string input;
        cin >> input;
        for(int m = 0; m < M; m++){
            int element = input[m]-48;

            if(element == 1){
                element = 100000;
            }
            row.push_back(element); 
        }
        miro.push_back(row);
    }

    queue< pair < int, int > > q;
    queue<int> q_value;
    q.push(make_pair(0,0));
    q_value.push(1);

    vector<pair<int, int > > move;
    move.push_back(make_pair(0, 1));
    move.push_back(make_pair(1, 0));
    move.push_back(make_pair(-1, 0));
    move.push_back(make_pair(0, -1));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int value = miro[x][y];
        int qValue = q_value.front();

        if(value > qValue){
            miro[x][y] = qValue;


            for(int i = 0; i < 4; i++){
                int newX = move[i].first + x;
                int newY = move[i].second + y;

                if(newX >= 0 && newX <N && newY >=0 && newY <M){
                    int nextValue = miro[newX][newY];
                    if(nextValue != 0){
                        if(qValue + 1 < miro[newX][newY]){
                            q.push(make_pair(newX, newY));
                            q_value.push(qValue + 1);
                        }
                    }
                }
            }
        }

        q.pop();
        q_value.pop();
    }


    cout << miro[N-1][M-1];
    return 0;
}
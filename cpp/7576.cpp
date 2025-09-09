#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair < int, int > > dMove;
int M, N;
int days = 0;
bool isChanged;
vector < vector <int > > box;

void BFS(int x, int y, queue < pair < int, int > > &q){
    if(box[y][x] == 0){
        box[y][x] = 1;
        isChanged = true;
        for(int i = 0; i<4; i++){
            int dx = dMove[i].first;
            int dy = dMove[i].second;
            if(x+dx >= 0 && x+dx < M && y+dy >=0 && y+dy < N){
                if(box[y+dy][x+dx] == 0){
                    q.push(make_pair(x+dx, y+dy));
                }
            }
        }
    }
}

void Queing(){
    queue< pair< int, int > > firstQ;
    queue< pair <int, int > > secondQ;
    bool mode = true;

    // 초기 1회 익어 있는 토마토 큐잉
    for(int y = 0; y < N;y++){
        for(int x = 0; x<M; x++){
            if(box[y][x] == 1){
                box[y][x] = 0;
                BFS(x,y, firstQ);
            }
        }
    }

    while(!firstQ.empty() || !secondQ.empty()){// 둘 다 empty일 때
        isChanged = false;
        if(mode){ // mode가 false일 때 firstQ 탐색
            while(!firstQ.empty()){
                pair<int, int> nextXY = firstQ.front();
                BFS(nextXY.first, nextXY.second, secondQ);
                firstQ.pop();
            }
        }
        else{ // 
            while(!secondQ.empty()){
                pair<int, int> nextXY = secondQ.front();
                BFS(nextXY.first, nextXY.second, firstQ);
                secondQ.pop();
            }
        }
        if(isChanged)
         {days++;}
        mode= !mode;
    }
}



int main(){
    cin >> M >> N;

    dMove.push_back(make_pair(0, 1));
    dMove.push_back(make_pair(1, 0));
    dMove.push_back(make_pair(0, -1));
    dMove.push_back(make_pair(-1, 0));

    for(int n= 0; n<N; n++){
        vector<int> newLine;
        int input;
        for(int m = 0; m<M; m++){
            cin >> input;
            newLine.push_back(input);
        }
        box.push_back(newLine);
    }

    Queing();

    // 안 익은 토마토 있는지 확인
    for(int y = 0; y<N; y++){
        for(int x = 0; x<M; x++){
            if(box[y][x] == 0){
                cout << "-1";
                return 0;
            }
        }
    }
    
    cout << days;
    return 0;
}
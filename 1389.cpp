/*
    1389 케빈 베이컨의 6단계 법칙 : https://www.acmicpc.net/problem/1389

    문제
        - N : 유저의 수
        - M : 친구 관계의 수

    문제 풀이
        - BFS 알고리즘을 통해 풀이.
            - 노드 사이의 거리가 1이기 때문에 가능.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int> > connection(N+1);

    for(int m = 0; m < M; m++){
        int a, b;
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    int min = 10000;
    int p;
    for(int n = 1; n <= N; n++){ // BFS
        bool visited[101];
        for(int i =1; i<= 100; i++){
            visited[i] = false;
        }

        int sum = 0;
        queue< pair< int, int > > q;
        q.push(make_pair(n,0));
        
        while(q.size() != 0){
            int index = q.front().first;
            int num = q.front().second;
            if(!visited[index]){
                for(int i =0; i<connection[index].size(); i++){
                    int nextIndex = connection[index][i];
                    if(!visited[nextIndex]){
                        q.push(make_pair(nextIndex, num + 1));
                    }
                }
                sum += num;
                visited[index] = true;
            }
            q.pop();
        }
        if(sum < min){
            min = sum;
            p = n;
        }
    }    

    cout << p;

    return 0;
}
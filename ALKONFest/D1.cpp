#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;
    int v[M];
    int v1[N][M];

    for(int i = 0; i < M; i++){
        cin >> v[i];
        v1[0][i] = v[i];
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j<M; j++){
            int value;
            cin >> value;
            if(j>0){
                v1[j] = value + v[j];
            }

        }
    }
}
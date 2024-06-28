#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector <int > > v;
    int v3[N][N];
    vector<int> vv;

    for(int x=0; x<M; x++){
        int value;
        cin >> value;
        vv.push_back(value);
        v3[0][x] = value;
    }
    v.push_back(vv);



    for(int y = 1; y<N; y++){
        vector <int> v2;
        for(int x=0; x< M; x++){
            int value;
            cin >> value;
            value= value + v[y-1][x];
            v2.push_back(value);

            if(x>0)
                v3[y][x] = value+v3[y-1][x-1];
            else
                v3[y][x] = value;
        }
        v.push_back(v2);     
    }
    


    for(int i = 0; i<Q; i++){
        int x, y;
        cin >> x >> y;

        cout << v3[x-1][y-1];
    
    }
}
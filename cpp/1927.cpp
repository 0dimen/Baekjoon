// 1927 https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue< int, vector <int>, greater <int > > q;
    int N;
    cin >> N;
    for(int n = 0; n < N ; n++){
        int x;
        cin >> x;
        
        if(x == 0){
            if(q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << q.top()<< "\n";
                q.pop();
            }
        }
        else{
            q.push(x);
        }
    }
    return 0;
}
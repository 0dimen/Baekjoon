#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> a;
    int A[N];
    
    for(int i = 0; i<N; i++){
        int n;
        cin >> n;
        int diff = n;
        if(n > i){
            diff = i;
        }
        a.push_back(make_pair(diff,n));
        A[N] = n;
    }
}
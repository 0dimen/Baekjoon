// 11399 ATM : https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> P;

    for(int i =0; i<N; i++){
        int p;
        cin >> p;
        P.push_back(p);
    }

    sort(P.begin(), P.end());

    int minP = 0;

    for(int i=0; i < N; i++)
        minP += P[i]*(N-i);
    cout << minP;
    return 0;
}
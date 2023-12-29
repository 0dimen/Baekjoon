// 이항 계수 1 11050 https://www.acmicpc.net/problem/11050

#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    long long int result = 1;
    for(int n = N-K+1; n<= N; n++){
        result *=n;
    }
    for(int k = 1; k<=K; k++){
        result /=k;
    }

    cout << result;
    return 0;
}
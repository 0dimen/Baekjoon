// 1003 피보나치 함수 https://www.acmicpc.net/problem/1003

/*
    피보나치 함수에서 0과 1이 나오는 횟수를 구한다.
    fibo(n) = fibo(n-1) + fibo(n-2)이다.
    따라서, 각각의 fibo(n-1)과 fibo(n-2)의 값이 존재하면, 해당 값을 더하여 fibo(n)을 구할 수 있다.
*/

#include <iostream>
using namespace std;

int zeros[41];
int ones[41];


int main(){
    for (int i = 0; i< 41; i++){
        zeros[i] = -1;
        ones[i] = -1;
    }
    zeros[0] = 1;
    ones[0] = 0;
    zeros[1] = 0;
    ones[1] = 1;

    int T, N;
    cin >> T;
    for (int t = 0; t<T; t++){
        cin >> N;
        
        for(int n = 2; n<=N; n++){
            zeros[n] = zeros[n-1] + zeros[n-2];
            ones[n] = ones[n-1] + ones[n-2];
        }
        cout << zeros[N] << " " << ones[N] << "\n";
    }


    return 0;
}


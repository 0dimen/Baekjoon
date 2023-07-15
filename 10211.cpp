// 10211 Maximum Subarray : https://www.acmicpc.net/problem/10211

#include <iostream>
using namespace std;

int main(){
    int T; // test case
    cin >> T;
    for (int t = 0; t < T; t++){ // test case loop
        int N; // array size
        cin >> N;

        int X[N];
        for (int n = 0; n < N; n++){ // enter array
            int input;
            cin >> input;
            X[n] = input;
        }

        int max = -1000; // -1000 < max

        for (int n = N; n >= 0; n--){ // sum of n size subarray
            for(int i = 0; i+n <N; i++){ 
                int sum = 0;
                
                for(int j = i; j <= i+n; j++) // calculate sum
                    sum += X[j];

                if (sum > max) // sum update
                    max = sum;
            }
        }
        cout << max << "\n";
    }

    return 0;
}
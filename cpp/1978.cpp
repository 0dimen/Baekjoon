// 1978번 소수 찾기 https://www.acmicpc.net/problem/1978
/*
    N개의 자연수가 주어진다. 자연수는 1000 이하이다.
    주어진 자연수의 소수의 개수를 구한다.

    주어진 수가 짝수면, 소수가 아니다. 따라서, 홀수의 값만 확인하면 되므로, 500개의 값만 확인하면 된다.
    따라서 최대로 걸리는 루프의 개수는 100*500 == 10^4이다.

*/


#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int result = 0;
    for(int n = 0; n<N; n++){
        int num;
        cin >> num;
        if(num == 1)
            continue;
        if(num == 2){
            result++;
            continue;
        }
        if(num%2 !=0){// 짝수가 아니면, 소수인지 확인.
            result++;
            for(int i = 3; i<num; i+=2){
                if(num%i == 0){
                    result--;
                    break;
                }
            }
        }     
    }
    cout << result;
    return 0;
}
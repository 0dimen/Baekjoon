// 2417번 정수 제곱근 : https://www.acmicpc.net/problem/2417

/*
문제 : 0~2^63 이하의 값의 정수형 제곱근 구하기.

풀이
    - 2^63은 64bit int 자료형 사용해야 함.

깨달은 점
    - unsigned long lond int, int64_t와 같은 자료형은 2^63을 담을 수 있다.
*/


#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // int64_t n;
    unsigned long long int n;
    cin >> n;

    unsigned long long int result = sqrt(n);
    if(result*result < n)
        result++;
    
    cout << result;
    return 0;
}
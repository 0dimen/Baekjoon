/*
18222 투에-모스 문자열

- 문제 풀이 :
    - 문자열은 XX'로 구성되어 있다.
        각각의 X는 xx', X'는 x'x의 형태로 세분화 된다.
    - 2^n-1 < k <= 2^n일 때
        1 ~ 2^n-1 -1번째 값은 X
        2^n-1 ~ 2^n번째 값은 X' 라고 가정한다.
    - k <= 2^n-1, X 문자열을, k > 2^n-1 X' 문자열에 속해있다고 본다.

- 알게 된 점 :
    - 나눗셈 시, (long long int) 자료형의 변수를 (int)로 계산하면, 오버플로우가 발생하여 잘못된 값을 반환함.
*/

#include <iostream>
using namespace std;

int main(){
    long long int k;
    cin >> k;
    long long int n = 1; // pivot으로 사용.
    while (n < k){
        n *= 2;
    }
    
    bool isReversed = false;
    while(n >= 1){
        if(k > n){
            k -= n;
            isReversed = !isReversed;
        }
        // else isReversed = isReversed;
        n = (long long int)n/2;
        
    }

    cout << isReversed;
    return 0;
}
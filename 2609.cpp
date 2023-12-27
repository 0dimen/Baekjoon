// 2609 최대공약수와 최대공배수 https://www.acmicpc.net/problem/2609

/*
    divider를 max(n,m)부터 시작하지 않고, 3부터 시작한 이유
        - 숫자의 분포로 보았을 때, 큰 자연수 사이의 값은 작은 소수를 인수로 가지고 있는 수가 더 많기 때문이다.
        작은 소수의 인자를 나누어 빠르게 n과 m을 작은 인자로 만드는 것이 더 빠를 것으로 보인다.
        "최대한 빨리 n과 m을 작은 값으로 나누는 것이 중요하다."
        큰 수에서 부터 인자를 빼는 것은 한 번에 소수로 다가간다는 점이 빠를 수도 있으나, 작은 수의 소수를 인수로 가지고 있는 경우 많은 숫자를 확인해야하므로 효율적이지 않아보인다.
*/
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int min = 1; // 최소공배수

    while(n%2==0 && m%2 == 0){ // 2 인자를 모두 추출
        n/=2;
        m/=2;
        min*=2;
    }

    int divider = 3;
    while(divider <=n && divider <= m){
        while(n%divider==0 && m%divider == 0){
            min*=divider;
            n/=divider;
            m/=divider;
        }
        divider+=2;
    }

    cout << min << "\n" << n*m*min;

    return 0;
}
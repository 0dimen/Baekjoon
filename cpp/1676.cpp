// 1676 팩토리얼 0의 개수 https://www.acmicpc.net/problem/1676
// fact에 10의 개수가 있는지 확인하는 것이 중요.
/*
    N!의 값이 500인 경우, long long int의 범위를 넘어가므로, N!값을 계산하여 결과를 도출하는 데에는 한계가 있다.
    따라서, 2와 5가 몇번 곱해졌는지 확인하여, 10의 재곱수를 확인하면 된다.
    2와 5가 몇 번 곱해졌는지 확인하고, 그 중 최솟값을 사용한다.
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int twoNum = 0;
    int fiveNum = 0;

    for(int n=1; n<=N; n++){
        int m = n;
        while(m%2 ==0){
            m /=2;
            twoNum++;
        }
        while(m%5 == 0){
            m /=5;
            fiveNum++;
        }
    }

    if(twoNum >fiveNum)
        cout << fiveNum;
    else
        cout << twoNum;

    return 0;
}
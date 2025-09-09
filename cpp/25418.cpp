// 25418 정수 a를 k로 만들기 : https://www.acmicpc.net/problem/25418

/*

배운 점
    - 같은 코드여도 순서가 중요하다.
        a와 k의 차이가 클 때는 +1 보다 *2를 하는 것이 더 빠르게 값에 도달할 수 있다.
        따라서 *2가 먼저 실행될 수 있도록 하는 것이 좋다.
        ? : 같은 방식으로 A -> K와 K -> A의 dfs를 진행했으나, 메모리 사용량은 dfsKtoA가 더 적었다. 이유는 k%2로 나누어 떨어지는 경우에만 dfs를 실행하기 때문이다.
*/

#include <iostream>
using namespace std;

int A, K;
int accList [1000001];
void dfsKtoA(int k, int acc){
    accList[k] = acc;

    if(accList[A] < acc) // 현재 최솟값보다 큰 경우 끝냄.
        return;

    if(k == A)
        return;
    
    else{
        acc++;

        if(k/2 >= A && k%2 == 0){ // 순서가 중요.
            if(accList[k/2] > acc)
                dfsKtoA(k/2, acc);
        }
        if(k-1 >= A){
            if(accList[k-1] > acc)
                dfsKtoA(k-1, acc);       
        }
    }
}
void dfsAtoK(int a, int acc){
    accList[a] = acc;

    if(accList[K] < acc) // 현재 최솟값보다 큰 경우 끝냄.
        return;

    if(K == a)
        return;
    
    else{
        acc++;

        if(a*2 <= K){ // 순서가 중요.
            if(accList[a*2] > acc)
                dfsAtoK(a*2, acc);
        }
        if(a+1 <= K){
            if(accList[a+1] > acc)
                dfsAtoK(a+1, acc);       
        }
    }
}

int main(){
    cin >> A >> K;

    for (int i = 0; i < 1000001 ; i++)
        accList[i] = 1000001;

    dfsKtoA(K,0);
    // dfsAtoK(A, 0);

    cout << accList[A];
    
    return 0;
}
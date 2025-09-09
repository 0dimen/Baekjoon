// 14606 피자 : https://www.acmicpc.net/problem/14606

#include <iostream>
using namespace std;

int fun = 0;
void dividePizza(int n){
    if(n<2)
        return;
    
    int n1, n2;

    n1 = int(n/2);
    n2 = n-n1;

    fun += n1*n2;

    dividePizza(n1);
    dividePizza(n2);
}

int main(){
    int N;
    cin >> N;
    
    
    dividePizza(N);

    cout << fun;

    return 0;
}
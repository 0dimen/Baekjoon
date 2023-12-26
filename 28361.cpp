// 28361번 크리스마스 https://www.acmicpc.net/problem/28361
// +2 -1 +2
// 3배수 : +1 +2 -1 +2 +2 -1 ... +2
// -1 +2 +
// 2개 남았을 때 : 
// 2 3 4 5 6 7

#include <iostream>
using namespace std;

int main(){
    int i =2;
    int N;
    cin >> N;
    int K = N;
    

    if((N-2)%3 == 0){
        cout << K << "\n1 2";
        while(i<N){
            cout << " " << i+2 << " " << i+1 << " " << i+3 ;
            i+= 3;
        }
    }
    else if((N-2)%3 == 1){
        cout << K << "\n1";
        i = 1;
        while(i<N-3){
            cout << " " << i+2 << " " << i+1 << " " << i+3 ;
            i+= 3;
        }
        cout << " " << N << " "<< N-1;
    }
    else{
        cout << K << "\n1 2";
        while(i<N-2){
            cout << " " << i+2 << " " << i+1 << " " << i+3;
            i+= 3;
        }
        cout << " " << N << " " << N-1;
    }
    cout << " " << 1;

    return 0;
}
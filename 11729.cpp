// 11729번 하노이 탑 이동 순서 : https://www.acmicpc.net/problem/11729

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int result =0;
    for(int i = 0; i=N; i++)
        result = result*2 + 1;
        
    cout << result;
    return 0;
}
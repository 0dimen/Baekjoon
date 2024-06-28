#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 값이 크거나, 같으면 불가.

int main(){
    int N;
    int result=0;
    cin >> N;
    
    int AList[1000];
    for(int i = 0; i<1000; i++){
        AList[i] = 0;
    }

    for (int i = 0; i<N; i++){
        int input;
        cin >> input;
        AList[input-1]++;
    }
    
    for(int i = 0; i<1000 ;i++){
        int v = AList[i];
        if(v>=2){
            result += 2;
        }else
            result += v;
    }

    cout << result;

}
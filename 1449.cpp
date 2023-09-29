// 1449 수리공 항승 : https://www.acmicpc.net/problem/1449

/*
- 문제 설명:
    물이 새는 곳 개수 : N
    테이프 길이 : L
    물이 새는 곳의 위치를 입력받음.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;

    vector<int> location; // 물 새는 곳 위치
    for(int i =0; i<N; i++){
        int locat;
        cin >> locat;
        location.push_back(locat);
    }

    sort(location.begin(), location.end());

    int n = 0;
     // 테이프 길이
    for(int i = 0; i<N; i++){
        int l = L-1;
        while(i+1 < N){
            l -= location[i+1] - location[i];
            if(l < 0)
                break;
            else
                i++;
        }
        n++;
    }

    cout << n;

    return 0;
}
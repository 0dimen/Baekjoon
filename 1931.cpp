// 1931 회의실 배정 : https://www.acmicpc.net/problem/1931
/*
- 문제 풀이:
    뒤에서 부터 시작 시간이 가장 늦은 것을 선택.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair <long, long > > t;

    for(int n = 0; n < N; n++){
        long t1, t2;
        cin >> t1 >> t2;
        t.push_back(make_pair(t1, t2));
    }

    sort(t.begin(), t.end());

    int max = 0;
    for(int n = N-1; n>=0; n--){
        int num = 1;
        long nStart = t[n].first;
        for(int m = n-1; m>=0; m--){
            if(t[m].second <= nStart){
                num++;
                nStart = t[m].first;
            }
            else
                continue;
        }
        if(num > max)
            max = num;
    }

    cout << max;

    return 0;
}
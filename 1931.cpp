// 1931 회의실 배정 : https://www.acmicpc.net/problem/1931
/*
- 문제 풀이:
    뒤에서 부터 시작 시간이 가장 늦은 것을 선택.
    greedy
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair <long, long> a, pair <long, long> b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    vector<pair <long, long > > t;

    for(int n = 0; n < N; n++){
        long t1, t2;
        
        cin >> t1 >> t2;
        t.push_back(make_pair(t1, t2));
    }

    sort(t.begin(), t.end(), compare);

    int max = 0;
    long end = 0;
    for(int n = 0; n<N; n++){
        if(t[n].first >= end){
            max++;
            end = t[n].second;
        }
    }

    cout << max;

    return 0;
}
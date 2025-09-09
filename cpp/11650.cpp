// 11650 좌표 정렬 : https://www.acmicpc.net/problem/11650
/*
    문제 : x, y 좌표를 N개 만큼 입력받고, x->y 순으로 정렬하여 출력한다.

    풀이 
    - x, y를 pair형으로 vector에 저장한다.
    - sort를 통해 정렬한다.

    배운점:
    - pair를 vector에 넣기 위해서는 make_pair를 통해 pair 형식을 맞춰야 한다.
        push_back({x, y}) 은 불가능했음.
    - algorithm의 sort는 quick sort임.
        pair형 vector에 대한 sort는 first->second순으로 오름차순으로 정렬됨.
*/


#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

int main(){ 
    int N;
    cin >> N;
    vector<pair<int, int> > v;
    
    for (int i = 0; i<N; i++){
        int x, y;
        cin >> x >> y;
        
        v.push_back(make_pair(x,y));// pair를 vector에 넣기 위해서는 make_pair를 통해 pair 형식을 맞춰야 한다.
    }

    // pair형 vector는 sort를 통해 first -> second 순으로 정렬된다.
    sort(v.begin(), v.end());

    for(auto point : v)
        cout << point.first << " " << point.second << "\n";
    
    return 0;
}
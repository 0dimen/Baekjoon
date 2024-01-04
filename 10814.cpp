// 10814 나이순 정렬 https://www.acmicpc.net/problem/10814
/*
    pair 형태 sort. vector<pair<>>형태를 sort하면, pair의 첫번째 인자 -> 두번째 인자를 기준으로 sorting 된다.
    
    그러나 본 문제에서는 나이가 같다면, 해당 멤버들에 대해서는 입력된 순서대로 출력되기를 원한다.
    따라서, 나이 -> 입력된 순서로 sorting이 되어야 한다.
    멤버는 {나이, 가입 순서, 이름} 형식으로 저장되어야 한다. tuple을 사용하여 sorting하면, 나이 -> 가입 순서 -> 이름 순으로 정렬된다.
    이 방식은 이름까지 정렬되어 비효율적이라는 단점이 있다. 또한 tuple이 터미널의 g++에서는 컴파일 에러가 생긴다.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main(){
    int N;
    vector<tuple<int, int, string > > members;
    cin >> N;
    for(int i = 0; i<N; i++){
        int n;
        string name;
        cin >> n >> name;
        members.push_back({n, i ,name});
    }
    sort(members.begin(), members.end());

    for(int i = 0; i< N; i++){
        cout << get<0>(members[i]) << " " << get<2>(members[i]) << "\n";
    }

    return 0;
}
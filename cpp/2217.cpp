// 2217 로프 : https://www.acmicpc.net/problem/2217

/*
- 문제 설명 :
    N개의 각각의 로프가 견딜수 있는 중량을 입력받는다.
    여러가지 가능 중량의 로프를 사용할 때에는
        로프 하나가 최대로 들어올릴 수 있는 무게 == 사용 로프들 중 최소 중량 로프
    임을 감안해야한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> w;
    for(int i = 0; i < N; i++){ // 값 입력
        int weight;
        cin >> weight;
        w.push_back(weight);
    }

    sort(w.begin(), w.end(), greater<int>()); // 내림차순 정렬

    int maxW = 0; // 최대 하중의 최솟값

    for(int i = 0; i < w.size(); i++){ // 최대 하중 구하기.
        if(i+1 < w.size())
            if(w[i+1] == w[i]) // 다음 값이 같은 값을 가지는 경우, 다음 인덱스에서 최댓값 갱신을 하도록 함.
                continue;
        
        int weight = w[i] * (i+1); // 로프 하나가 최대로 들어올릴 수 있는 무게 == 사용 로프 중 최소 하중
        if(weight > maxW)
            maxW = weight;
    }

    cout << maxW;

    return 0;
}
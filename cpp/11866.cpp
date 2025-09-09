// 11866 요세푸스 문제 0 https://www.acmicpc.net/problem/11866

/*
    순환하는 배열의 index를 구하는 방법 : index %= array.size(),
    index += K-1 에서 1을 뺀 이유 : 매번 배열에서 값이 1개씩 삭제되기 때문.
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> person;
    vector<int> permutaion;

    for(int i = 1; i<N+1; i++)
        person.push_back(i);
    
    int index = 0;
    int erasedNum = 0;
    cout << "<";

    while(!person.empty()){
        index+=K-1;
        index %= person.size();
        
        erasedNum++;

        cout << person[index];
        if(erasedNum != N)
            cout << ", ";
        else
            cout << ">";
        person.erase(person.begin() + index);
    }

    return 0;
}
// 11866 요세푸스 문제 0 https://www.acmicpc.net/problem/11866

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
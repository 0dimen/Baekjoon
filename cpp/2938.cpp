// 2938 3으로 나누어 떨어지지 안흔 배열 : https://www.acmicpc.net/problem/2938

/*
- 두 수를 합했을 때 3의 배수가 되는 배열을 만든다.

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v;
    vector<pair < int,int > > connectV;
    int connectNum[N];
    
    for (int i = 0; i< N; i++)
        connectNum[i] = 0;
    
    for (int i = 0; i < N; i++){
        int input;
        cin >> input;

        v.push_back(input);
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if((v[i] + v[j])%3 == 0){
                connectV.push_back(make_pair(i,j));
                connectV.push_back(make_pair(j,i));
                connectNum[i]++;
                connectNum[j]++;
            }
        }
    }
    
    sort(connectV.begin(), connectV.end());
    for(auto i: connectV){
        cout << i.first << ","<< i.second << "\n";
    }
    for(int i = 0; )
    return 0;
}
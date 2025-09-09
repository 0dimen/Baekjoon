// 2798 블랙잭 https://www.acmicpc.net/problem/2798

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> num;

    for(int i =0; i< N; i++){
        int input;
        cin >> input;
        num.push_back(input);
    }

    sort(num.begin(), num.end());

    int maxNum = -1;

    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            for(int k = j+1; k <N; k++){
                int sum = num[i] + num[j] + num[k];
                if(sum <= M){
                    if(sum >maxNum)
                        maxNum = sum;
                }
            }
        }
    }

    cout << maxNum;
    
    return 0;
}
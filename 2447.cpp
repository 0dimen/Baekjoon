// 2447 별 찍기 - 10 : https://www.acmicpc.net/problem/2447

#include <iostream>
#include <vector>
using namespace std;

vector<vector <string> > result;

void initialization(int n){ // *로 이루어진 n*n배열 만들기.
    vector<string> input;
    for(int i = 0; i< n; i++) // *로 row 만들기
        input.push_back("*");
    
    for(int i = 0; i<n; i++)
        result.push_back(input);
}

void star(int N, int n){
    if(n < 3) // 초기 조건 : 3 이상.
        return;
    
    n /= 3;

    for(int i = n; i < N; i += 3*n){
        for (int j = n; j < N; j+= 3*n){
            for (int x = 0; x < n; x++){
                for(int y = 0; y < n; y++){
                    result[i+x][j+y] = " ";
                }
            }
        }
    }
    star(N, n);
}

int main(){
    int N;
    cin >> N;

    initialization(N);
    star(N,N);

    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << result[i][j];
        cout << "\n";
    }
    
    return 0;

}
// 1764 듣보잡 https://www.acmicpc.net/problem/1764

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, M;
    vector<string> names;
    vector<string> result;
    int resultNum = 0;
    cin >> N >> M;

    for(int i = 0; i <N+M; i++){
        string name;
        cin >> name;
        names.push_back(name);
    }

    sort(names.begin(), names.end());

    for(int i = 0; i < N+M-1; i++){
        if(names[i] == names[i+1]){
            resultNum++;
            result.push_back(names[i]);
            i++;
        }
    }

    cout << resultNum << "\n";

    for(int i = 0; i<resultNum; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
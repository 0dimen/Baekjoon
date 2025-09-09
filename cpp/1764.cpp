// 1764 듣보잡 https://www.acmicpc.net/problem/1764

/*
    N과 M개의 배열에 모두 포함되어 있는 문자열 찾기.
    N과 M개의 배열에는 각각 중복되지 않은 값들이 입력되기 때문에, 모두 포함되어 있는 문자열은 N과 M의 문자열에서 총 2번 입력된다.
    하나의 vector에 N+M개의 이름을 모두 입력받고, sort하여, 배열을 0에서 부터 N+M-1 인덱스까지의 값을 확인하면서 중복 값이 있는지 확인하면 된다.
    확인 방법은 다음 인덱스 값의 name과 같은 값을 가지는지 확인하고, 가지지 않는다면 다음 인덱스로 넘어가 같은 방법을 반복한다.
*/

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
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v;

    for(int i=0; i<N; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        cout << v[i] << "\n";
    }

    return 0;
}
// 2428번 표절 : https://www.acmicpc.net/problem/2428

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> F;

int binary_search(int maxIndex){
    int targetValue = F[maxIndex]*0.9;

    int i = maxIndex/2;
    int high = maxIndex;

    while(high < i){
        int mid = (high + i)/2;
        if(F[i] == targetValue)
            return i;
        else if(F[i] > targetValue)
            i = mid -1;
        else
            high = mid+1;
    }
    cout << i << endl;
    if(i < 0 || maxIndex > i + 1)
        return 0;

    if (F[i] < targetValue && maxIndex > i + 1)
        i++;
    targetValue = F[i];
    while(i > 0){ // 중복 값이 존재하는지 확인.
        if(F[i-1] == targetValue)
            i--;
        else
            break;
    }
    return i;
}

int main(){
    int N;
    cin >> N;

    for(int i =0; i<N; i++){
        int size;
        cin >> size;
        F.push_back(size);
    }

    sort(F.begin(), F.begin()+N); // size(F_i) <= size(F_j) 형태로 만듦.

    int pairNum = 0;

    for(int j = N-1; j>0; j--)
        pairNum += (j-binary_search(j));

    cout << pairNum;
    return 0;
}

int binarySearch(int arr[], int l, int r, int x){
    if (r >= 1){
        int mid = l + (r -1) / 2;
    }
}
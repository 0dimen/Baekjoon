// https://www.acmicpc.net/problem/11726

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long int temp1 = 1;
    long int temp2 = 2;
    if(n == 1)
        temp2 = temp1;
    else if(n == 2){
        temp2 = temp2;
    }
    else{
        for (int i = 3; i<=n; i++){
        long int sum = (temp1+temp2)%10007;
        temp1 = temp2;
        temp2 = sum;
        }
        
        
    }
    cout << temp2;
    return 0;
}
// 10610 30 : https://www.acmicpc.net/problem/10610

#include <iostream>
using namespace std;

vector<int> v;

int makeNum(int F, )

int main(){
    string N;
    cin >> N;

    for(auto c : N)
        v.push_back((int)c - '0');
    
    sort(v.begin(), v.end(), greater<int>());

    if(v.back() == 0)
        v.pop_back();
    else{
        cout << "-1";
        return 0;
    }

    int maxFacto = 1;
    for(int i = 1; i <= v.size() ; i++)
        maxFacto *= i;
// 21 -> 12
// 321 -> 312 -> 231 -> 213 -> 132 -> 123
// 4321 -> 4312 -> 4231 -> 4213 -> 4132 -> 4123 -> 3421 -> 
// 1    -> 2    -> 3    -> 4    -> 5    -> 6    -> 7
//      -> 2.0  -> 6.3  -> 6.2  -> 6.1  -> 6.0  -> 24.7
//      -> 2    -> 2.1.1-> 2.2.0-> 2.2.1-> 2.2.2-> 6.1.1
// 6%4 => 2
// 1, 2, 6, 24, => Comb
// 54321 -> 
    while(v.front() != 0){
        int num;
        int facto;
        int digit; //자릿수
        int turn;
        int F = 1; // Factorial Num
        vector<int> f;
        for(int i = turn; i > 1; i/digit){
            
        }

    }

    return 0;
}
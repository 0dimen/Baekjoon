// 1541 : https://www.acmicpc.net/problem/1541
// -가 나오면 다음 -가 나오기 전까지의 숫자를 모두 괄호에 묶어서 뺀다.
// 즉 - 이후의 숫자는 모두 -가 된다고 생각하면 된다.


#include <iostream>
#include <sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int sum = 0;
    bool isMinus = false;

    istringstream ss(str);
    string buff;
    
    while(getline(ss, buff, '-')){
        istringstream sub(buff);
        string buff2;
        int temp = 0;
        while(getline(sub, buff2, '+')){
            temp += atoi(buff2.c_str());
        }

        if(isMinus == true){
            sum -= temp;
        }
        else{
            sum += temp;
            isMinus = true;
        }

    }
    cout << sum;
    return 0;
}
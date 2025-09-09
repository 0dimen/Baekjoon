// 1259번 팰린드롬수 https://www.acmicpc.net/problem/1259
// 팰린드롬 : 단어를 역순으로 해도 똑같은 단어

#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    while(str != "0"){
        int maxIndex = str.length()-1;
        bool flag = true;
        for(int i = 0; i<=maxIndex/2; i++){
            if(str[i] != str[maxIndex-i]){
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
        
        cin >> str;
    }

    return 0;
}
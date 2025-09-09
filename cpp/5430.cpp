// 5430 https://www.acmicpc.net/problem/5430
// reverse의 시간 복잡도는 N. 따라서, 시간복잡도를 줄이기 위해, p에서 R이 나오는 경우 매번 reverse하지 않고, isReverse를 사용하여 모드를 변경한다.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    
    for(int t = 0; t<T ; t++){
        string p;
        cin >> p;
        int listSize;
        cin >> listSize;
        bool flag = true;

        bool isReversed = false;

        string str;
        cin >> str;
        istringstream ss(str.substr(1,str.size()-2));
        string buffer;
        vector<int> n;
        if(listSize != 0){
            while(getline(ss, buffer, ',')){
                n.push_back(atoi(buffer.c_str()));
            }
        }

        for(int i = 0; i<p.size(); i++){
            switch(p[i]){
                case 'R':
                    isReversed = !isReversed;
                    break;
                case 'D':
                    if(n.empty()){
                        cout << "error" << '\n';
                        i = p.size();
                        flag = false;
                        break;
                    }
                    else{
                        if(isReversed)
                            n.pop_back();
                        else
                            n.erase(n.begin());
                        break;
                    }
                        
            }
        }
        if(flag){
            if(isReversed)
                reverse(n.begin(), n.end());
            cout << "[";
            if(n.size()!= 0){
                cout << n[0];
                for(int i =1; i<n.size(); i++){
                    cout << ","<< n[i];
                }
            }
            cout << "]" << "\n";
        }
        
    }
    return 0;
}


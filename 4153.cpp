#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a;
    for(int i= 0; i<3; i++){
        int side;
        cin >> side;
        a.push_back(side);
    }
    while(!(a[0] == a[1] && a[1] == a[2] && a[2]== 0)){
        sort(a.begin(), a.end());

        if(a[0]*a[0] +a[1]*a[1] ==a[2]*a[2] )
            cout << "right\n";
        else
            cout << "wrong\n";
        cin >> a[0] >> a[1] >> a[2];
    }
    return 0;
}


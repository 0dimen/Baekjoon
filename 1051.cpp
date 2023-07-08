// 1051번 숫자 정사각형 : https://www.acmicpc.net/problem/1051

/*
문제 : N * M의 직사각형을 입력받는다. 4개의 꼭짓점에 같은 값을 가지고 있는 가장 큰 정사각형의 넓이를 출력한다.

풀이
    - list로 값을 N * M 직사각형 값을 받아 인덱스로 접근한다.
        - (n,m) (n+l, m) (n+l, m+l) (n, m+l)의 값을 비교한다. (l : 정사각형의 변의 길이)
        - 최댓값을 찾아야 하므로 가장 긴 l의 길이부터 탐색한다.
            - l의 길이의 최댓값 min(N,M)이다.

배운 점
    - Test1
        1. ==는 앞에서부터 계산
        2. 여러개의 ==에서 ==에서 0과 1은 각각 true와 false 의미. 즉, int가 bool의 역할.
            n1 == n2 == n3 == n4..와 같은 경우, 앞의 n1 == n2 부터 차례로 값을 0(true), 1(false)로 치환하는 것을 알 수 있었다.
            또한 0과 1은 각각 true, false로 여겨져, 각별히 주의할 필요가 있다.
            예를 들어, 3 == 3 == 0 == 0은 true이다. 왜냐하면 3 == 3 => true(1), 1 == 0 => false(0), 0 == 0 => true.
            따라서 0과 1이 없는 값을 여러개 비교하는 경우, ==를 다중으로 사용하는 것이 가능하나, 0과 1이 있는 경우 값의 왜곡이 생길 수 있다.
        
            해결 :
                - ==와 &를 함께 사용하여 ==가 겹쳐져 사용되는 것을 막는다.
                - 0과 1이 없는 값이 없는 경우 사용 가능.


*/

#include <iostream>
#include <cmath>
using namespace std;

/*Test1
    void f1(int n1, int n2 , int n3){
        if(n1 == n2 == n3)
            cout << "true ";
        else
            cout << "false ";
        
        cout << n1 << " == " << n2 << " == " << n3 << "\n";
    }
*/


int main(){
    int N, M;
    cin >> N >> M;

    int rectangle[N][M];

    for(int n = 0; n < N; n++){ // 직사각형 값 입력
        string input;
        cin >> input;
        for(int m =0; m<M; m++){
            rectangle[n][m]=input[m] - '0';
        }    
    }

    int maxLength = (N < M) ? N : M;

    while(maxLength > 1){
        bool isSquare = false;
        for(int n = 0; n<=N-maxLength; n++){
            if(isSquare)
                break;
            for(int m = 0; m<=M-maxLength; m++){
                int l = maxLength -1;
                
                int elem = rectangle[n][m];
                if(elem== rectangle[n+l][m] && 
                    elem == rectangle[n+l][m+l] &&
                    elem == rectangle[n][m+l]){
                        isSquare = true;
                        break;
                    }
            }
        }
        if(isSquare)
            break;
        else
            maxLength--;
    }

    // result
    cout << pow(maxLength, 2);
    return 0;

    /* Test1
        // 하나의 항을 true or false로 치환하고 있음을 알 수 있음.
        f1(0,0,1); // true
        f1(0,0,0); // false

        // 앞에서 부터 치환하는 것으로 알 수 있음.
        f1(0,0,5); // false
        f1(5,0,0); // true

        // 앞에서 부터 치환하는 것 확인
        f1(1,0,0); // true
        f1(0,0,1); // true
        f1(5,5,1); // true
    */
    
}


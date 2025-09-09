// 11501 주식 : https://www.acmicpc.net/problem/11501

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
- 문제 풀이 : 
    주가가 가장 높은 날 == 파는 날.
    오늘을 제외하고 주가가 높아지는 날 존재 == 사는 날.
    가격이 떨어지기만 하는 경우 == 아무것도 안한다.
- 풀이 1 : 틀림
- 풀이 2 : 시간 초과
    - 시간 초과를 해결하기 위해 최댓값만 갱신하는 형태로 변경.
*/



#define MAXPRICE 10001

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        
        int price[MAXPRICE]; // index == 가격, value == 개수
        vector<int> days; // index  -1 == 날짜, value == 가격
        vector<int> prices; // 가격의 종류
        
        for(int i =0; i<MAXPRICE; i++) // 0으로 초기화
            price[i] = 0;

        for(int n = 0; n<N; n++){
            int input;
            cin >> input;
            days.push_back(input);
            if (price[input] == 0)
                prices.push_back(input);
            price[input]++;
        }

        sort(prices.begin(), prices.end());

        long long income = 0;
        int buyNum = 0;

        for(int n = 0; n< N; n++){
            int todayPrice = days[n];
            while(price[prices.back()] == 0) // 최댓값 갱신
                prices.pop_back();

            int highPrice = prices.back();
            price[todayPrice]--;
            // 매도
            if(highPrice == todayPrice){
                income += buyNum* todayPrice;
                buyNum = 0;
            }
            else{
                // 매수
                if(todayPrice < highPrice){ // 오늘보다 높은 날이 있는 경우.
                    buyNum++;
                    income -= todayPrice;
                }
                // 행동 X
            }
        }
        printf("%lld\n", income);

    }
    return 0;
}


/* 풀이 1
        int buy = 0;
        int income = 0;
        int maxPrice = -1;
        for(int n = 0; n<N; n++){
            int todayPrice = s[n];
            if(maxPrice == todayPrice){// 파는 경우
                income += maxPrice*(buy);
                buy = 0;
                maxPrice = -1;
                continue;
            }
            maxPrice = todayPrice;
            for(int m = n+1; m<N; m++){// 사는 경우
                if(s[m]>maxPrice)
                    maxPrice = s[m]; // maxPrice의 값, maxPrice 존재 여부.
            }
            if(maxPrice > todayPrice){
                buy++;
                income -= todayPrice;
            }
            else // 행동 X
                break;
                
        }
*/

/* 풀이 2
vector<int> s;
        vector<pair <int, int > > highPoint;
        for(int n = 0; n<N; n++){
            int input;
            cin >> input;
            s.push_back(input);
            highPoint.push_back(make_pair(input, n));
        }

        sort(highPoint.begin(), highPoint.end());

        long long income = 0;
        int buy = 0;
        for(int n = 0; n<N; n++){
            int todayPrice = s[n];
            
            if(todayPrice == highPoint.back().first){ // 매도
                int highIndex = highPoint.size() -1;
                while(highPoint[highIndex].second != n)
                    highIndex--;
                
                income += todayPrice*buy;
                buy = 0;
                highPoint.erase(highPoint.begin() + highIndex);
            }
            
            else{
                bool bought = false;
                while(!bought){
                    if(todayPrice < highPoint.back().first){ // 매수
                        if(n >= highPoint.back().second){ // 지나간 날짜인 경우.
                            highPoint.pop_back();
                            continue;
                        }
                        else{ // 매수 가능한 경우
                            buy++;
                            income -= todayPrice;
                            bought = true;
                            break;
                        }
                    }
                    else{ // 행동 X
                        break;
                    }
                }
            }
        }
        printf("%lld\n", income);

*/
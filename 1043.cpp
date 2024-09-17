// 1043 https://www.acmicpc.net/problem/1043
// 진실을 아는 사람이 포함된 파티는 모두 진실만 말해야함.
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    set<int> tPersons; // 진실을 아는 사람.
    vector<set<int > > connection(N+1); // DFS 탐색을 위한 리스트
    vector<bool> isChecked;

    int tNum;
    cin >> tNum;
    for(int n = 0; n<tNum; n++){
        int truePerson;
        cin >> truePerson;
        tPersons.insert(truePerson);
    }

    for(int n =0; n<=tNum; n++){ // connection, isChecked 초기화
        isChecked.push_back(false);
    }
    

    vector< vector <int > > partyList;
    
    for(int m = 0; m<M; m++){ // DFS 배열 생성
        int pNum;
        cin >> pNum;
        vector<int> party;

        // 첫번째 사람에게 연결되어있으면 DFS를 통해 party 안의 모두와 연결될 수 있음.
        int person;
        cin >> person;
        party.push_back(person);
        for(int p = 1; p<pNum; p++){
            int nextPerson;
            cin >> nextPerson;
            connection[person].insert(nextPerson);
            connection[nextPerson].insert(person);
            party.push_back(nextPerson);
        }
        partyList.push_back(party);
    }

    for(auto tPerson : tPersons){// 진실을 아는 사람을 root로 DFS
        if(isChecked[tPerson] == true){
            continue;
        }
        else{
            queue<int> q;
            for(auto person : connection[tPerson]){
                q.push(person);
            } 
            while(!q.empty()){
                int p = q.front();
                if(isChecked[p]){
                    q.pop();
                }
                else{
                    for(auto nextP : connection[p]){
                        q.push(nextP);
                    }
                    tPersons.insert(p);
                    q.pop();
                    isChecked[p] = true;
                }
            }
        }
    }

    int result = M;

    for(auto party : partyList){ // 진실을 아는 사람이 있는 파티를 제외
        for(auto p : party){
            if(tPersons.find(p) != tPersons.end()){
                result--;
                break;
            }
        }
    }

    cout << result;
    return 0;
}
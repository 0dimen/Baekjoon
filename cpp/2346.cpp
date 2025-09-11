#include <iostream>
#include <vector>

using namespace std;

int calc(int n, int m){
  if(n <0){
    n = (n * (-1)) % m;
    return n * (-1);
  }
  else{
    return n % m;
  }
}

int main()
{
  int N;
  cin >> N;
  vector<pair<int,int>> v;
  for (int i = 0; i < N; i++)
  {
    int n;
    cin >> n;
    v.push_back(make_pair(i+1,n));
  }
  int idx = 0;
  while (v.size() > 1)
  {
    int currentNum = v[idx].first;
    int move = v[idx].second;
    v.erase(v.begin() + idx);
    
    if (move > 0)
      idx--;
    idx = (idx + move);
    idx = calc(idx, v.size());

    if (idx < 0)
    {
      idx += v.size();
    }

    cout << currentNum;
  }
  cout << v[0].first;
}

#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

  vector<vector<int>>arr = {
    {4, 10, 15, 24, 26},
    {0, 9, 12, 20},
    {5, 18, 22, 30}
  };

  priority_queue<
  pair<int, pair<int,int>>,
  vector<pair<int, pair<int,int>>>,
  greater<pair<int, pair<int,int>>>> pq;

  int maxi = 0;

  for(int i=0;i<3;i++){
    pq.push({arr[i][0], {i, 0}});
    maxi = max(maxi, arr[i][0]);
  }

  int ansL = 0;
  int ansR = 100000;

  while (true) {

    auto x = pq.top();
    pq.pop();

    int mini = x.first;
    int row = x.second.first;
    int col = x.second.second;

    if (maxi - mini < ansR - ansL) {
      ansL = mini;
      ansR = maxi;
    }

    col++;

    if (col == arr[row].size()){
      break;
    }

    pq.push({arr[row][col], {row, col}});
    maxi = max(maxi, arr[row][col]);
    }
    cout << ansL << " " << ansR;
  return 0;
}
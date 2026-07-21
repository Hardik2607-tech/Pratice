#include<iostream>
#include<vector>
using namespace std;


struct Job{
  char id;
  int deadline;
  int profit;
};

bool cmp(Job a, Job b) {
  return a.profit > b.profit;
}

int main(){
    int n;
    cin>>n;

    vector<Job> jobs(n);

    int maxdeadline = 0;
    for(int i=0;i<n;i++){
      cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
      maxdeadline = max(maxdeadline,jobs[i].deadline);
    }

    sort(jobs.begin(), jobs.end(), cmp);

    vector<int> slot(maxdeadline + 1, -1);

    int profit = 0;

    for (int i = 0; i < n; i++) {
      for (int j = jobs[i].deadline; j >= 1; j--) {
        if (slot[j] == -1) {
          slot[j] = i;
          profit += jobs[i].profit;
          break;
        }
      }
    }
    cout << "Maximum Profit = " << profit;
}
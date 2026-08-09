#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int maxArea(vector<int>& heights) {

    stack<int> st;
    int ans = 0;

    for (int i = 0; i < heights.size(); i++) {

        while (!st.empty() && heights[i] < heights[st.top()]) {

            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            ans = max(ans, height * width);
        }

        st.push(i);
    }

    int n = heights.size();

    while (!st.empty()) {

        int height = heights[st.top()];
        st.pop();

        int width;

        if (st.empty())
            width = n;
        else
            width = n - st.top() - 1;

        ans = max(ans, height * width);
    }

    return ans;
}

int main(){
  
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }


  cout<<endl<<maxArea(arr)<<endl;
  return 0;
}

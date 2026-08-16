#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n - 2; i++){

        // Skip duplicate first elements
        if(i > 0 && arr[i] == arr[i-1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while(left < right){

            int sum = arr[i] + arr[left] + arr[right];

            if(sum == 0){

                cout << arr[i] << " "
                     << arr[left] << " "
                     << arr[right] << endl;

                // Skip duplicates
                while(left < right && arr[left] == arr[left+1])
                    left++;

                while(left < right && arr[right] == arr[right-1])
                    right--;

                left++;
                right--;
            }

            else if(sum < 0){
                left++;
            }

            else{
                right--;
            }
        }
    }

    return 0;
}
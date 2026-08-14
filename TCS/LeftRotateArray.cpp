#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    k = k % n;

    // 1. Reverse first k elements
    int start = 0;
    int end = k - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // 2. Reverse remaining elements
    start = k;
    end = n - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // 3. Reverse entire array
    start = 0;
    end = n - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
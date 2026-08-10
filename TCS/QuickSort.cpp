#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& arr, int low, int high) {
    if (low >= high){
      return;
    }
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
          swap(arr[i], arr[j]);
          i++;
        }
    }

    swap(arr[i], arr[high]);

    quicksort(arr, low, i - 1);
    quicksort(arr, i + 1, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    return 0;
}
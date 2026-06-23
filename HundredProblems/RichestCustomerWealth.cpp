#include<iostream>
#include<vector>
using namespace std;

int main(){

    int i , j;
    cin >> i >> j;

    vector<vector<int>> arr(i , vector<int>(j));

    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            cin >> arr[k][l];
        }
    }
    cout<<endl;
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
          cout << arr[k][l] << " ";
        }
        cout << endl;
    }

    return 0;
}
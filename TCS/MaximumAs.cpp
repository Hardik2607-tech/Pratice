#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int L;
    cin >> L;

    int n = s.length();
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == 'a')
            count++;

        if ((i + 1) % L == 0) {
          maxCount = max(maxCount, count);
          count = 0;
        }
    }

    maxCount = max(maxCount, count);

    cout << maxCount;

    return 0;
}
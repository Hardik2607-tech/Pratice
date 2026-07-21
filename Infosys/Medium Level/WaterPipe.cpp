#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

  int n, p;
  cin >> n >> p;

  vector<int> out(n + 1, 0);
  vector<int> in(n + 1, 0);
  vector<int> dia(n + 1, 0);

  for (int i = 0; i < p; i++) {

    int a, b, d;
    cin >> a >> b >> d;

    out[a] = b;
    in[b] = a;
    dia[a] = d;
  }
  cout<<endl;
  for (int i = 1; i <= n; i++) {

    if (in[i] == 0 && out[i] != 0) {

      int curr = i;
      int mn = INT_MAX;

      while (out[curr] != 0) {
        mn = min(mn, dia[curr]);
        curr = out[curr];
      }
      cout<< i << " " << curr << " " << mn << endl;
    }
  }
  return 0;
}
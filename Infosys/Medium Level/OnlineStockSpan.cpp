#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);

    stack<int> st;   // stores indices

    for (int i = 0; i < n; i++) {

        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        if (st.empty())
            span[i] = i + 1;
        else
            span[i] = i - st.top();

        st.push(i);
    }

    return span;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> price(n);

    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    vector<int> ans = stockSpan(price);

    cout << "Stock Span: ";
    for (int x : ans)
        cout << x << " ";

    return 0;
}
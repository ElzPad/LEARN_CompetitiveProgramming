#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int main(void) {
    vector<int> a, b;
    long long res1=0, res2=0;

    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i<N; i++)
        res1 += abs(a[i]-b[i]);
    for (int i=0; i<N; i++)
        res2 += a[i] * count(b.begin(), b.end(), a[i]);
    cout << "Q1: " << res1 << "\n";
    cout << "Q2: " << res2 << "\n";
}
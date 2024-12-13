#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int checkIfSafe1(vector<int> a) {
    int ver = a[0]>a[1] ? -1 : 1;
    for (int i=0; i<a.size()-1; i++) {
        if (ver==1 && ( a[i+1]<a[i]+1 || a[i+1]>a[i]+3))
            return 0;
        else if (ver==-1 && ( a[i+1]>a[i]-1 || a[i+1]<a[i]-3))
            return 0;
    }
    return 1;
}

int checkIfSafe2(vector<int> a) {
    int ver = a[0]>a[1] ? -1 : 1;
    bool firstError = false;

    for (int i=0; i<a.size()-1; i++) {
        if (
            (ver==1 && ( a[i+1]<a[i]+1 || a[i+1]>a[i]+3)) ||
            (ver==-1 && ( a[i+1]>a[i]-1 || a[i+1]<a[i]-3))
        ) {
            if (!firstError) {
                firstError = true;
                a.erase(a.begin() + i);
                i--;
            } else
                return 0;
        }
    }
    return 1;
}

int main(void) {
    long long res1=0, res2=0;
    string line;

    ifstream file("input.txt");

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    while (getline(file, line)) {
        vector<int> vec;
        
        stringstream ss(line);
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }
        res1 += checkIfSafe1(vec);
        res2 += checkIfSafe2(vec);
    }
    cout << "Q1: " << res1 << "\n";
    cout << "Q2: " << res2 << "\n";
}
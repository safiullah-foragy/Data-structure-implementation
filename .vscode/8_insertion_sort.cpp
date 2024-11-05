#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int sz;
    cin >> sz;
    
    vector<int> v(sz);

   
    for (int i = 0; i < sz; i++) {
        cin >> v[i];
    }

    // Insertion sort algorithm
    for (int i = 1; i < sz; i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j - 1]);
            j--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < sz; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // Uncomment below if multiple test cases are needed
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

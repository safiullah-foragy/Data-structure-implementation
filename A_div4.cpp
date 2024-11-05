#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    int mini = INT_MAX; // Start with a large value
    
    for (int c = a; c <= b; c++) {
        // Assuming a hypothetical expression, e.g., c - a + b - c;
        mini = min(mini, c - a + b - c);
    }
    
    cout << mini << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

#include <iostream>
using namespace std;

// Recursive implementation of Ackermann function
unsigned long long ackermann(unsigned long long m, unsigned long long n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0; // In case of invalid input
}

int main() {
    unsigned long long m, n;
    cout << "Enter values for m and n: ";
    cin >> m >> n;

    unsigned long long result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}

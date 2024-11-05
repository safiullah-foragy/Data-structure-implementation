#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

int main() {
    int number;
   
    cin >> number;

   
    int result = factorial(number);

  
    cout << "Factorial of " << number << " is " << result << endl;

    return 0;
}

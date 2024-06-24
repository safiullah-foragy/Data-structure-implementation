#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
   
    for (int i = 0; i < n - 1; ++i) {
        
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11, 10};
    
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    bubbleSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    return 0;
}

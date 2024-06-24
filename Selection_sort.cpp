#include <bits/stdc++.h>
#include <vector>

using namespace std;


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
  
    for (int i = 0; i < n - 1; ++i) {
        
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}


void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11,10,100};
    
    cout << "Original array: ";
    printArray(arr);
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}

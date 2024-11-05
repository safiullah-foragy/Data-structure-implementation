#include<bits/stdc++.h>
#include <vector>
using namespace std;

// Function to merge two sorted halves
void merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<int> temp;

    // Merge the two halves into temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from the right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to the original array
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

// Recursive function to implement merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the left half
        mergeSort(arr, left, mid);
        // Sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    
    cin >> n;

    vector<int> arr(n);
  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

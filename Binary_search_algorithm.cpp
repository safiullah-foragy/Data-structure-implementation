#include <bits/stdc++.h>


using namespace std;


int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        
        if (nums[mid] == target)
            return mid;

       
        if (nums[mid] < target)
            left = mid + 1;
    
        else
            right = mid - 1;
    }

    
    return -1;
}

int main() {
    vector<int> num = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target ;
    cin>>target;
    
    int result = binarySearch(num, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;
    
    return 0;
}

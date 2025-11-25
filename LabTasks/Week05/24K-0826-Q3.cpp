#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << binarySearch(arr, 0, n - 1, 23) << endl;
    cout << binarySearch(arr, 0, n - 1, 45) << endl;
    cout << binarySearch(arr, 0, n - 1, 100) << endl;
    
    return 0;
}
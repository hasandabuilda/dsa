#include <iostream>

int BinarySearch(int* arr, int length, int target) {
    int low = 0;
    int high = length - 1;
    int mid = (high + low) / 2;
    
    while (low <= high) {
        if (arr[mid] > target) {
            high = mid - 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            return mid;
        }
        mid = (high + low) / 2;
    }
    return -1;
}

int BinarySearchRecursive(int* arr, int low, int high, int target) {
    int mid = (high + low) / 2;
    if (low <= high) {
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            return BinarySearchRecursive(arr, mid+1, high, target);
        }
        else {
            return BinarySearchRecursive(arr, low, mid-1, target);
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    assert(BinarySearch(arr, length, 3) == 2);
    assert(BinarySearch(arr, length, 0) == -1);

    assert(BinarySearchRecursive(arr, 0, length-1, 9) == 8);
    assert(BinarySearchRecursive(arr, 0, length-1, 10) == -1);
}
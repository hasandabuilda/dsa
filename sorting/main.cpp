#include <iostream>

int length = 10;
int goodArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int badArr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int avg[] = {7, 1, 4, 10, 6, 2, 3, 5, 8, 9};

void CopyArrays(int good[], int bad[], int arr[]) {
    for (int i = 0; i < length; i++) {
        good[i] = goodArr[i];
        bad[i] = badArr[i];
        arr[i] = avg[i];
    }
}

void BubbleSort(int* arr) {
    bool sorted = false;
    int j = 0;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < length-1-j; i++) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                sorted = false;
            }
        }
        j++;
    }
}

void Merge(int* arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    k--;
    while (k >= 0) {
        arr[start + k] = temp[k];
        k--;
    }
}

void MergeSort(int* arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

// Similar to the one below but you choose the first element
// as the pivot. Then you iterate starting from the second
// element, and place all the smallest elements to the left
void QuickSort(int* arr, int start, int end) {
    if (start < end) {
        int pivot = arr[start];
        int i = start;
        for (int j = start + 1; j <= end; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i], arr[start]);
        QuickSort(arr, start, i-1);
        QuickSort(arr, i+1, end);
    }
}

// Idea here is to always choose the pivot as the last element
// You also have a second index that starts outside the array
// at start - 1. Whenever you find an element smaller than the
// pivot, increment this second index and swap the smaller
// element with this second index. This ensures that you are
// filling up the left half of the array with the smallest
// elements. When you are done traversing, the second index
// denotes the end of the smallest elements, so place the pivot
// at this index + 1. Your two sub arrays are up to the index,
// and then after the index + 2
// More specifically, there always will be at most pivot - 1
// elements that you need to bring over to the left side of the
// array and this second index will do that for you
// void QuickSort(int* arr, int start, int end) {
//     if (start < end) {
//         int pivot = arr[end];
//         int i = start - 1;

//         for (int j = start; j < end; j++) {
//             if (arr[j] <= pivot) {
//                 i++;
//                 std::swap(arr[i], arr[j]);
//             }
//         }
//         std::swap(arr[i+1], arr[end]);

//         QuickSort(arr, start, i);
//         QuickSort(arr, i + 2, end);
//     }
// }

// Idea here is to choose a random pivot, and then close in
// from both ends of the array with two indices. As long as
// elements are placed correctly at the end, increment/decrement
// those indices. Once you reach two elements that are correct,
// swap their values. Keep going until the two indices pass each
// each other. They will equal right at the pivot, and then
// due to increment/decrement, j will be one less than the pivot
// and i one greater. These are exactly the new sub arrays
// Note that this does not seem to account for multiple elements
// being equal to the pivot, but I think you can just add a
// condition to the while loops to include equal to and a check
// for not being the pivot index
// void QuickSort(int* arr, int start, int end) {
//     if (start == end) {
//         return;
//     }

//     int pivotIndex = rand() % (end - start + 1);
//     int pivot = arr[start + pivotIndex];
//     int i = start;
//     int j = end;

//     while (i <= j) {
//         while (arr[i] < pivot) {
//             i++;
//         }
//         while (arr[j] > pivot) {
//             j--;
//         }

//         if (i <= j) {
//             if (i < j) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//             i++;
//             j--;
//         }
//     }

//     // More specifically, this covers the edge case of one of i
//     // or j never changing. This means j < start and i > end
//     // which would mess up everything up.
//     // And you can't just add the condition if (i == j) to the
//     // above loop before increment/decrement because you need
//     // this difference to kick out of the loop
//     if (start < j) {
//         QuickSort(arr, start, j);
//     }
//     if (end > i) {
//         QuickSort(arr, i, end);
//     }
// }

void SiftDown(int* arr, int index, int length) {
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    if (leftChild < length) {
        if (arr[index] < arr[leftChild]) {
            largest = leftChild;
        }
    }
    if (rightChild < length) {
        if (arr[index] < arr[rightChild]) {
            // Remember, you only want to swap the largest value
            if (arr[leftChild] < arr[rightChild]) {
                largest = rightChild;
            }
        }
    }

    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        SiftDown(arr, largest, length);
    }
}

// Uses a max heap
void HeapSort(int* arr, int length) {
    // Heapify
    // Assume the latter half is already on the bottom
    // Start from the middle and work backwards to build
    // the heap from the bottom up
    for (int i = length/2 - 1; i >= 0; i--) {
        SiftDown(arr, i, length);
    }

    // Continuously swap max value to the end
    for (int i = length - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        SiftDown(arr, 0, i);
    }
}

void InsertionSort(int* arr, int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while ((arr[j] > key) && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void SelectionSort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void CountingSort(int* arr, int length, int k) {
    int countArr[k+1];
    for (int i = 0; i <= k; i++) {
        countArr[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        countArr[arr[i]]++;
    }

    int m = 0;
    for (int i = 0; i <= k; i++) {
        while (countArr[i] > 0) {
            arr[m++] = i;
            countArr[i]--;
        }
    }
}

// Modified counting sort
// You count sort based on the digit you are looking at
// To actually sort elements of the original array however
// based on how the digits should be ordered, you also look
// at the cumulative total of hits across all digits.
// You start from the end of the cumulative number and iterate
// down because you know that the last digit of the cumulative
// array is guaranteed to have the max size. Moreover, the
// cumulative total actually tells you where this digit should
// be placed in the sorted array. You decrement in case multiple
// numbers have the same digit.
// And you don't need to worry
// about getting any 0s from the cumulative array because the 
// cumulative array is based on the digits that were found is
// accessed by those same digits
void CountingRadixSort(int* arr, int length, int digit) {
    int count[10];
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    int output[length];
    for (int i = 0; i < length; i++) {
        output[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[(arr[i] / digit) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    int j = 0;
    for (int i = length - 1; i >= 0; i--) {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
    }
}

void RadixSort(int* arr, int length) {
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int digit = 1; max / digit > 0; digit *= 10) {
        CountingRadixSort(arr, length, digit);
    }
}

bool IsSorted(int* arr) {
    bool sorted = true;
    for (int i = 0; i < length; i++) {
        if (arr[i] != i+1) {
            sorted = false;
            for (int j = 0; j < length; j++) {
                std::cout << arr[j] << " ";
            }
            std::cout << std::endl;
            break;
        }
    }
    return sorted;
}

int main(int argc, char* argv[]) {

    std::cout << __cplusplus << std::endl;

    int bubbleGood[10], bubbleBad[10], bubbleArr[10];
    CopyArrays(bubbleGood, bubbleBad, bubbleArr);
    BubbleSort(bubbleGood);
    assert(IsSorted(bubbleGood));
    BubbleSort(bubbleBad);
    assert(IsSorted(bubbleBad));
    BubbleSort(bubbleArr);
    assert(IsSorted(bubbleArr));

    int mergeGood[10], mergeBad[10], mergeArr[10];
    CopyArrays(mergeGood, mergeBad, mergeArr);
    MergeSort(mergeGood, 0, length - 1);
    assert(IsSorted(mergeGood));
    MergeSort(mergeBad, 0, length - 1);
    assert(IsSorted(mergeBad));
    MergeSort(mergeArr, 0, length - 1);
    assert(IsSorted(mergeArr));

    int quickGood[10], quickBad[10], quickArr[10];
    CopyArrays(quickGood, quickBad, quickArr);
    QuickSort(quickGood, 0, length - 1);
    assert(IsSorted(quickGood));
    QuickSort(quickBad, 0, length - 1);
    assert(IsSorted(quickBad));
    QuickSort(quickArr, 0, length - 1);
    assert(IsSorted(quickArr));

    int heapGood[10], heapBad[10], heapArr[10];
    CopyArrays(heapGood, heapBad, heapArr);
    HeapSort(heapGood, 10);
    assert(IsSorted(heapGood));
    HeapSort(heapBad, 10);
    assert(IsSorted(heapBad));
    HeapSort(heapArr, 10);
    assert(IsSorted(heapArr));

    int insertGood[10], insertBad[10], insertArr[10];
    CopyArrays(insertGood, insertBad, insertArr);
    InsertionSort(insertGood, 10);
    assert(IsSorted(insertGood));
    InsertionSort(insertBad, 10);
    assert(IsSorted(insertBad));
    InsertionSort(insertArr, 10);
    assert(IsSorted(insertArr));

    int selectGood[10], selectBad[10], selectArr[10];
    CopyArrays(selectGood, selectBad, selectArr);
    SelectionSort(selectGood, 10);
    assert(IsSorted(selectGood));
    SelectionSort(selectBad, 10);
    assert(IsSorted(selectBad));
    SelectionSort(selectArr, 10);
    assert(IsSorted(selectArr));

    int countGood[10], countBad[10], countArr[10];
    CopyArrays(countGood, countBad, countArr);
    CountingSort(countGood, 10, 10);
    assert(IsSorted(countGood));
    CountingSort(countBad, 10, 10);
    assert(IsSorted(countBad));
    CountingSort(countArr, 10, 10);
    assert(IsSorted(countArr));

    int radixGood[10], radixBad[10], radixArr[10];
    CopyArrays(radixGood, radixBad, radixArr);
    RadixSort(radixGood, 10);
    assert(IsSorted(radixGood));
    RadixSort(radixBad, 10);
    assert(IsSorted(radixBad));
    RadixSort(radixArr, 10);
    assert(IsSorted(radixArr));

    std::cout << "They all worked!!!" << std::endl;
    return 0;
}
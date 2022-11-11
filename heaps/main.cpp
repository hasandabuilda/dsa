#include "max-heap.hpp"

int main(int argc, char* argv[]) {
    MaxHeap* heap = new MaxHeap(7);

    assert(heap->IsEmpty());
    assert(heap->GetSize() == 0);
    heap->Insert(1);
    heap->Insert(2);
    heap->Insert(3);
    heap->Insert(4);
    heap->Insert(5);
    assert(heap->GetMax() == 5);

    heap->Insert(6);
    heap->Insert(7);
    assert(heap->GetMax() == 7);
    assert(heap->IsEmpty() == false);
    assert(heap->GetSize() == 7);

    heap->Remove(0);
    assert(heap->GetMax() == 6);
    heap->Remove(4);
    assert(heap->GetSize() == 5);

    assert(heap->ExtractMax() == 6);
    assert(heap->ExtractMax() == 5);
    assert(heap->ExtractMax() == 4);
    assert(heap->GetSize() == 2);

    int arr[] = {3, 4, 1, 5, 2};
    heap->HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    assert(arr[3] == 4);
    assert(arr[4] == 5);

    return 0;
}
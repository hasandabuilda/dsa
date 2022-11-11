#ifndef __MAX_HEAP_HPP__
#define __MAX_HEAP_HPP__

#include <iostream>

class MaxHeap {
    public:
        MaxHeap(int maxSize);
        ~MaxHeap();
        void Insert(int value);
        void SiftUp(int index);
        int GetSize();
        bool IsEmpty();
        int GetMax();
        int ExtractMax();
        void SiftDown(int index);
        void Remove(int index);
        
        void Heapify();
        void HeapSort(int* arr, int length);

    private:
        int numNodes_;
        int maxSize_;
        int* nodes_;
};

MaxHeap::MaxHeap(int maxSize)
: maxSize_(maxSize)
{
    numNodes_ = 0;
    nodes_ = new int[maxSize_];
}

MaxHeap::~MaxHeap() {
    delete[] nodes_;
}

void MaxHeap::Insert(int value) {
    if (numNodes_ < maxSize_) {
        nodes_[numNodes_] = value;
        SiftUp(numNodes_);
        numNodes_++;
    }
    else {
        std::cout << "Heap is full" << std::endl;
    }
}

void MaxHeap::SiftUp(int index) {
    if (index > 0) {
        int parent = nodes_[(index-1)/2];
        if (parent < nodes_[index]) {
            nodes_[(index-1)/2] = nodes_[index];
            nodes_[index] = parent;
            SiftUp((index-1)/2);
        }
    }
}

int MaxHeap::GetSize() {
    return numNodes_;
}

bool MaxHeap::IsEmpty() {
    return numNodes_ == 0;
}

int MaxHeap::GetMax() {
    if (numNodes_ > 0) {
        return nodes_[0];
    }
    else {
        std::cout << "Error: Heap is empty" << std::endl;
        return -1;
    }
}

int MaxHeap::ExtractMax() {
    int max = nodes_[0];
    nodes_[0] = nodes_[numNodes_ - 1];
    numNodes_--;
    if (numNodes_ > 0) {
        SiftDown(0);
    }
    return max;
}

void MaxHeap::SiftDown(int index) {
    if ((2*index + 2) < numNodes_) {
        int leftChild = nodes_[2*index + 1];
        int rightChild = nodes_[2*index + 2];
        if (leftChild > rightChild) {
            if (nodes_[index] < leftChild) {
                nodes_[2*index + 1] = nodes_[index];
                nodes_[index] = leftChild;
                SiftDown(2*index + 1);
            }
        }
        else if (rightChild > leftChild) {
            if (nodes_[index] < rightChild) {
                nodes_[2*index + 2] = nodes_[index];
                nodes_[index] = rightChild;
                SiftDown(2*index + 2);
            }
        }
    }
    else if ((2*index + 1) < numNodes_) {
        int leftChild = nodes_[2*index + 1];
        if (nodes_[index] < leftChild) {
            nodes_[2*index + 1] = nodes_[index];
            nodes_[index] = leftChild;
        }
    }
}

void MaxHeap::Remove(int index) {
    if (index < numNodes_) {
        nodes_[index] = nodes_[numNodes_-1];
        numNodes_--;
        SiftDown(index);
    }
    else {
        std::cout << "Index out of bounds" << std::endl;
    }
}

void MaxHeap::Heapify() {
    for (int i = maxSize_/2; i >= 0; i--) {
        SiftDown(i);
    }
}

void MaxHeap::HeapSort(int* arr, int length) {
    delete nodes_;
    nodes_ = arr;
    numNodes_ = length;
    maxSize_ = length;

    Heapify();
    for (int i = numNodes_ - 1; i >= 0; i--) {
        nodes_[i] = ExtractMax();
    }
    arr = nodes_;
}

#endif
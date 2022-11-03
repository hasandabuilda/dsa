#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include "list_element.hpp"
#include <stdlib.h>
#include <iostream>

template <class T>
class LinkedList {
    public:
        explicit LinkedList() : head_(nullptr) {}
        ~LinkedList();
        LinkedList(const LinkedList &) = delete;
        LinkedList &operator=(const LinkedList &) = delete;
        int Size() const;
        void PushFront(T value);
        bool Empty() const;
        const T& ValueAt(int index) const;
        void PrintDebug() const;
        const T PopFront();
        void PushBack(T value);
        const T PopBack();
        const T Front();
        const T Back();
        void Insert(int index, T value);
        void Erase(int index);
        const T ValueNFromEnd(int n);
        void Reverse();
        void RemoveValue(T value);
};

#endif
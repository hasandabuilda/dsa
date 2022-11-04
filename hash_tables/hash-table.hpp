#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#include "hash-element.hpp"
#include <iostream>

template <class T>
class HashTable {
    public:
        HashTable(int size);
        ~HashTable();
        void Add(T key, T value);
        bool Exists(T key);
        T Get(T key);
        void Remove(T key);

    private:
        int Hash(T key);
        int size_;
        HashElement<T>* hash_table_;
};

template <class T>
HashTable<T>::HashTable(int size)
: size_(size)
{
    hash_table_ = new HashElement<T>[size_];
    for (int i = 0; i < size_; i++) {
        hash_table_[i].SetEmpty();
    }
}

template <class T>
HashTable<T>::~HashTable() {
    delete[] hash_table_;
}

template <class T>
void HashTable<T>::Add(T key, T value) {
    int hash_code = Hash(key);

    for (int i = hash_code; i < size_; i++) {
        if (hash_table_[i].GetKey() == key) {
            hash_table_[i].SetValue(value);
            return;
        }
        else if (hash_table_[i].IsEmpty()) {
            hash_table_[i].SetKey(key);
            hash_table_[i].SetValue(value);
            return;
        }
    }
    std::cout << "Error: Hash Table is full" << std::endl;
}

template <class T>
bool HashTable<T>::Exists(T key) {
    int hash_code = Hash(key);

    for (int i = hash_code; i < size_; i++) {
        if (hash_table_[i].GetKey() == key) {
            return true;
        }
    }
    return false;
}

template <class T>
T HashTable<T>::Get(T key) {
    int hash_code = Hash(key);

    for (int i = hash_code; i < size_; i++) {
        if (hash_table_[i].GetKey() == key) {
            return hash_table_[i].GetValue();
        }
    }
    std::cout << "Error: Key not found" << std::endl;
    return NULL;
}

template <class T>
void HashTable<T>::Remove(T key) {
    int hash_code = Hash(key);

    for (int i = hash_code; i < size_; i++) {
        if (hash_table_[i].GetKey() == key) {
            hash_table_[i].SetKey(NULL);
            hash_table_[i].SetValue(NULL);
            return;
        }
    }
    std::cout << "Error: Key not found" << std::endl;
}

template <class T>
int HashTable<T>::Hash(T key) {
    return key % size_;
}

#endif
#ifndef __HASH_ELEMENT_HPP__
#define __HASH_ELEMENT_HPP__

#include <iostream>

template <class T>
class HashElement {
    public:
        HashElement() {}
        T GetKey() { return key_;  }
        T GetValue() { return value_; }
        void SetKey(T key) { key_ = key; filled_ = true; }
        void SetValue(T value) { value_ = value; }
        bool IsEmpty() { return filled_ == false; }
        void SetEmpty() { filled_ = false; key_ = NULL; value_ = NULL; }

    private:
        T key_;
        T value_;
        bool filled_;
};

#endif
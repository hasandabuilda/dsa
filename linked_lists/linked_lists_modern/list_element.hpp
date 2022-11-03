#ifndef __LIST_ELEMENT_HPP__
#define __LIST_ELEMENT_HPP__

#include <memory>

template <class T>
class ListElement {
    public:
        ListElement(const T &value) : next_(nullptr), data_(value) {}
        ~ListElement() {}
        ListElement(const ListElement &) = delete;
        ListElement &operator=(const ListElement &) = default;

        const T& GetData() const { return data_ ;}
        ListElement<T>* GetNext() const { return next_; }
        void SetData(const T &data)
        void SetNext(ListElement<T> *elem) { next_ = elem; }

    private:
        ListElement<T>* next_;
        T data_;
};

#endif
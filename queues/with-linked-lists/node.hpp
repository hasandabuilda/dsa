#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <iostream>

template <class T>
class Node {
    public:
        Node(T value) : m_next(NULL), m_value(value) {};
        Node<T>* GetNext() { return m_next; };
        T GetValue() { return m_value; };
        void SetNext(Node<T>* nextNode) { m_next = nextNode; };
        void SetValue(T value) { m_value = value; };

    private:
        Node<T>* m_next;
        T m_value;
};

#endif
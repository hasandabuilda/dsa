#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "node.hpp"
#include <iostream>

template <class T>
class Queue {
    public:
        Queue();
        ~Queue();
        void Enqueue(T value);
        T Dequeue();
        bool Empty();

    private:
        Node<T>* m_head;
        Node<T>* m_tail;
};

template <class T>
Queue<T>::Queue() : m_head(NULL), m_tail(NULL) {};

template <class T>
Queue<T>::~Queue() {
    delete m_head;
    delete m_tail;
}

template <class T>
void Queue<T>::Enqueue(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!m_head) {
        m_head = newNode;
    }
    m_tail->SetNext(newNode);
    m_tail = newNode;
}

template <class T>
T Queue<T>::Dequeue() {
    if (!m_head) {
        exit(EXIT_FAILURE);
        std::cout << "Queue has no elements" << std::endl;
        return NULL;
    }
    else {
        T poppedValue = m_head->GetValue();
        if (m_head->GetNext()) {
            delete m_head;
            m_head = m_head->GetNext();
        }
        else {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }
    }
}

template <class T>
bool Queue<T>::Empty() {
    return !m_head;
}

#endif
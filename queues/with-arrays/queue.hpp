#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

template <class T>
class Queue {
    public:
        Queue(int size);
        ~Queue();
        void Enqueue(T value);
        T Dequeue();
        bool Empty();
        bool Full();

    private:
        T* m_data;
        int m_read;
        int m_write;
        int m_size;
};

template <class T>
Queue<T>::Queue(int size) {
    std::cout << "Creating a queue" << std::endl;
    m_read = 0;
    m_write = 0;
    m_size = size;
    m_data = new T[m_size];
}

template <class T>
Queue<T>::~Queue() {
    std::cout << "Destroying a queue" << std::endl;
}

template <class T>
void Queue<T>::Enqueue(T value) {
    if (Full()) {
        std::cout << "Queue is full" << std::endl;
    }
    else {
        m_data[m_write] = value;

        if ((m_write + 1) == m_size) {
            m_write = 0;
        }
        else {
            m_write++;
        }
    }
}

template <class T>
T Queue<T>::Dequeue() {
    if (Empty()) {
        std::cout << "Queue is empty" << std::endl;
        return NULL;
    }
    else {
        T popValue = m_data[m_read];
        m_data[m_read] = NULL;
        if ((m_read + 1) == m_size) {
            m_read = 0;
        }
        else {
            m_read++;
        }
        return popValue;
    }
}

template <class T>
bool Queue<T>::Empty() {
    return m_read == m_write;
}

template <class T>
bool Queue<T>::Full() {
    if ((m_write + 1) == m_size) {
        return m_read == 0;
    }
    else {
        return ((m_write + 1) == m_read);
    }
}

#endif
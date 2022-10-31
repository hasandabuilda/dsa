#include "vector.hpp"
#include <iostream>

Vector::Vector(int cap) {
    std::cout << "Creating a new vector" << std::endl;
    if (cap < 1) {
        std::cout << "Cannot make a vector of that size" << std::endl;
        exit(EXIT_FAILURE);
    }
    else if (cap < 16) {
        m_capacity = 16;
    }
    else {
        m_capacity = cap;
    }
    int arr[m_capacity];
    m_elems = arr;
}

Vector::~Vector() {
    std::cout << "Successfully deleted" << std::endl;
}

int Vector::capacity() { return m_capacity; }
int Vector::size() { return m_size; }
bool Vector::is_empty() { return m_size == 0; }

int Vector::at(int index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    return *(m_elems + index);
}

int* Vector::push(int value) {
    if (m_size < m_capacity) {
        *(m_elems + m_size) = value;
        m_size++;
    }
    else {
        int arr[2 * m_capacity];
        for (int i = 0; i < m_capacity; i++) {
            arr[i] = *(m_elems + i);
        }
        arr[m_capacity] = value;
        m_elems = arr;
        m_size++;
        m_capacity *= 2;
    }
    return m_elems;
}

int* Vector::insert(int index, int value) {
    if (index >= 0 && index < m_size) {
        int arr[m_capacity+1];
        for (int i = 0; i < m_capacity + 1; i++) {
            if (i == index) {
                arr[i] = value;
            }
            else if (i < index) {
                arr[i] = *(m_elems + i);
            }
            else {
                arr[i] = *(m_elems + i - 1);
            }
        }
        m_elems = arr;
        m_size++;
        return m_elems;
    }
    else if (index == m_size) {
        return this->push(value);
    }
    else {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
        return m_elems;
    }
}

int* Vector::prepend(int value) {
    return this->insert(0, value);
}

int Vector::pop() {
    int poppedValue = *(m_elems + m_size - 1);
    *(m_elems + m_size - 1) = 0;
    m_size--;
    return poppedValue;
}

int* Vector::del(int index) {
    if (index < 0 || index >= m_size) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = index; i < m_size - 1; i++) {
            *(m_elems + i) = *(m_elems + i + 1);
        }
        m_size--;
    }
    return m_elems;
}

int* Vector::rem(int value) {
    for (int i = 0; i < m_size; i++) {
        if (*(m_elems + i) == value) {
            del(i);
        }
    }
    return m_elems;
}

int Vector::find(int value) {
    for (int i = 0; i < m_size; i++) {
        if (*(m_elems + i) == value) {
            return i;
        }
    }
    return -1;
}

void Vector::resize(int new_capacity) {
    int arr[new_capacity];
    for (int i = 0; i < m_size; i++) {
        arr[i] = *(m_elems + i);
    }
    m_elems = arr;
    m_capacity = new_capacity;
}
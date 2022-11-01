#include "ll.hpp"
#include <iostream>

LinkedList::LinkedList(int value) {
    std::cout << "Creating a linked list" << std::endl;

    Node* first = new Node;
    first->value = value;
    first->next = NULL;
    m_head = first;
}

LinkedList::~LinkedList() {
    std::cout << "Destroying the linked list" << std::endl;
    Node* node = m_head;
    while(node->next != NULL) {
        node = node->next;
        delete node;
    }
    delete m_head;
}

int LinkedList::size() {
    Node* node = m_head;
    int count = 1;
    while (node->next != nullptr) {
        node = node->next;
        count++;
    }
    return count;
}

bool LinkedList::empty() {
    if (m_head->next != NULL) {
        return true;
    }
    else {
        return false;
    }
}

int LinkedList::value_at(int index) {
    Node* node = m_head;
    for (int i = 0; i < index; i++) {
        if (node->next != NULL) {
            node = node->next;
        }
        else {
            exit(EXIT_FAILURE);
            std::cout << "Index out of bounds" << std::endl;
            return -1;
        }
    }
    return node->value;
}

LinkedList::Node* LinkedList::push_front(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = m_head;
    m_head = newNode;
    return m_head;
}

int LinkedList::pop_front() {
    int firstValue = m_head->value;
    delete m_head;
    m_head = m_head->next;
    return firstValue;
}

LinkedList::Node* LinkedList::push_back(int value) {
    Node* node = m_head;
    while (node->next != NULL) {
        node = node->next;
    }
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    node->next = newNode;
    return m_head;
}

int LinkedList::pop_back() {
    Node* node = m_head->next;
    Node* prevNode = m_head;
    while (node->next != NULL) {
        prevNode = node;
        node = node->next;
    }
    prevNode->next = NULL;
    int nodeValue = node->value;
    delete node;
    return nodeValue;
}

int LinkedList::front() {
    return m_head->value;
}

int LinkedList::back() {
    Node* node = m_head;
    while(node->next != NULL) {
        node = node->next;
    }
    return node->value;
}

LinkedList::Node* LinkedList::insert(int index, int value) {
    Node* node = m_head;
    for (int i = 0; i < index-1; i++) {
        if (node->next != NULL) {
            node = node->next;
        }
        else {
            exit(EXIT_FAILURE);
            std::cout << "Index out of bounds" << std::endl;
            return node;
        }
    }
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = node->next;
    node->next = newNode;
    return m_head;
}

LinkedList::Node* LinkedList::erase(int index) {
    Node* node = m_head;
    for (int i = 0; i < index - 1; i++) {
        if (node->next != NULL) {
            node = node->next;
        }
        else {
            exit(EXIT_FAILURE);
            std::cout << "Index out of bounds" << std::endl;
            return node;
        }
    }
    if (node->next != NULL) {
        delete node->next;
        node->next = node->next->next;
        return m_head;
    }
    else {
        exit(EXIT_FAILURE);
        std::cout << "Index out of bounds" << std::endl;
        return node;
    }
}

int LinkedList::value_n_from_end(int n) {
    int size = 1;
    Node* node = m_head;
    while (node->next != NULL) {
        size++;
    }
    if (n > size) {
        exit(EXIT_FAILURE);
        std::cout << "Index out of bounds" << std::endl;
        return -1;
    }
    else {
        int index = size - n;
        node = m_head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->value;
    }
}

LinkedList::Node* LinkedList::reverse() {
    LinkedList* reverseList = new LinkedList(m_head->value);
    Node* node = m_head;
    while (node->next != NULL) {
        reverseList->push_front(node->value);
        node = node->next;
    }
    reverseList->push_front(node->value);
    m_head = reverseList->get_head();
    return m_head;
}

LinkedList::Node* LinkedList::remove_value(int value) {
    Node* node = m_head;
    int count = 0;
    if (node->value == value) {
        return erase(value);
    }
    while (node->next != NULL) {
        node = node->next;
        count++;
        if (node->value == value) {
            return erase(count);
        }
    }
    exit(EXIT_FAILURE);
    std::cout << "Value not found" << std::endl;
    return m_head;
}

LinkedList::Node* LinkedList::get_head() {
    return m_head;
}
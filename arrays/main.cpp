#include <iostream>
#include "vector.hpp"

int main() {

    int capacity = 2;
    Vector* vec = new Vector(capacity);

    // Testing
    assert(vec->capacity() == 16);
    vec->push(2);
    assert(vec->size() == 1);
    assert(vec->at(0) == 2);
    assert(vec->is_empty() == false);
    vec->push(4);
    vec->insert(1, 5);
    assert(vec->at(1) == 5);
    assert(vec->at(2) == 4);
    vec->prepend(10);
    assert(vec->at(0) == 10);
    assert(vec->at(1) == 2);
    vec->pop();
    assert(vec->size() == 3);
    vec->del(0);
    assert(vec->size() == 2);
    assert(vec->at(0) == 2);
    assert(vec->find(12) == -1);
    for (int i = 0; i < 16; i++) {
        vec->push(1);
    }
    assert(vec->capacity() == 32);
    assert(vec->at(16) == 1);
    assert(vec->at(0) == 2);


    delete vec;
    std::cout << "All tests passed" << std::endl;
    return 0;
}
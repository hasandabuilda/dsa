#include <iostream>
#include "ll.hpp"

int main() {
    std::cout << "Hello World" << std::endl;
    LinkedList* ll = new LinkedList(1);

    assert(ll->size() == 1);
    assert(ll->empty() == false);
    assert(ll->value_at(0) == 1);
    
    ll->push_front(10);
    ll->push_back(7);
    assert(ll->value_at(1) == 1);
    assert(ll->pop_front() == 10);
    assert(ll->pop_back() == 7);

    assert(ll->front() == 1);
    assert(ll->back() == 1);

    ll->insert(0,6);
    ll->erase(0);
    assert(ll->value_n_from_end(1) == 1);

    ll->push_back(2);
    ll->push_back(3);
    ll->reverse();
    assert(ll->value_at(0) == 3);
    
    ll->remove_value(2);
    assert(ll->value_at(1) == 1);


    delete ll;
}
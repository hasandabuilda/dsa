#include "queue.hpp"

int main(int argc, char* argv[]) {
    Queue<int> iq(5);

    assert(iq.Empty());
    iq.Enqueue(1);
    iq.Enqueue(2);
    iq.Enqueue(3);
    iq.Enqueue(4);
    iq.Enqueue(5);
    assert(iq.Empty() == false);
    assert(iq.Full());
    assert(iq.Dequeue() == 5);
    assert(iq.Dequeue() == 4);
    assert(iq.Dequeue() == 3);
    assert(iq.Dequeue() == 2);
    assert(iq.Dequeue() == 1);
    assert(iq.Empty());
    assert(iq.Full() == false);

    return 0;
}
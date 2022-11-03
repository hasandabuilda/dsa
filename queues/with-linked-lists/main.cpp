#include "queue.hpp"

int main(int argc, char* argv[]) {
    Queue<int> iq;

    assert(iq.Empty());
    iq.Enqueue(1);
    iq.Enqueue(2);
    iq.Enqueue(3);
    assert(iq.Empty() == false);
    assert(iq.Dequeue() == 1);
    assert(iq.Dequeue() == 2);
    assert(iq.Dequeue() == 3);
    assert(iq.Empty());
    return 0;
}
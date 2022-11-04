#include "hash-table.hpp"

int main(int argc, char* argv[]) {

    HashTable<int> iht(5);
    iht.Add(0,0);
    iht.Add(1,1);
    iht.Add(2,2);
    iht.Add(6,6); // Should be added to index 3
    assert(iht.Exists(1));
    assert(iht.Exists(2));
    assert(iht.Exists(6));
    assert(iht.Get(0) == 0);
    assert(iht.Get(1) == 1);
    assert(iht.Get(6) == 6);
    iht.Remove(6);
    assert(iht.Get(6) == NULL);

    return 0;
}
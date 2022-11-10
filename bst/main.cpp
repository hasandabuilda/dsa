#include "binary-search-tree.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    BinarySearchTree* bst = new BinarySearchTree(10);

    bst->Insert(3);
    bst->Insert(12);
    bst->Insert(6);
    bst->Insert(1);
    bst->Insert(11);
    bst->Insert(15);
    bst->PrintValues();

    assert(bst->GetNodeCount() == 7);
    assert(bst->IsInTree(3));
    assert(bst->IsInTree(-1) == false);
    assert(bst->GetHeight() == 3);
    assert(bst->GetMin() == 1);
    assert(bst->GetMax() == 15);
    assert(bst->IsBinarySearchTree());
    
    bst->DeleteValue(10);
    assert(bst->IsInTree(10) == false);
    std::cout << std::endl;
    bst->PrintValues();
    std::cout << std::endl;

    bst->PrintValuesByLevel();

    bst->DeleteTree();

    return 0;
}
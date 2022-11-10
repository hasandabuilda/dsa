#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

#include <iostream>
#include <queue>

class BinarySearchTree {
    public:
        BinarySearchTree(int value);
        void Insert(int value);
        int GetNodeCount();
        void PrintValues();
        void DeleteTree();
        bool IsInTree(int value);
        int GetHeight();
        int GetMin();
        int GetMax();
        bool IsBinarySearchTree();
        void DeleteValue(int value);
        void PrintValuesByLevel();

    private:
        int value_;
        BinarySearchTree* left_;
        BinarySearchTree* right_;
        void ShiftTree(BinarySearchTree* bst);
        void RemoveChild(int value);
};

BinarySearchTree::BinarySearchTree(int value) {
    value_ = value;
    left_ = nullptr;
    right_ = nullptr;
}

void BinarySearchTree::Insert(int value) {
    if (value == value_) {
        std::cout << "Value already exists" << std::endl;
    }
    else if (value > value_) {
        if (right_) {
            right_->Insert(value);
        }
        else {
            BinarySearchTree* newBST = new BinarySearchTree(value);
            right_ = newBST;
        }
    }
    else {
        if (left_) {
            left_->Insert(value);
        }
        else {
            BinarySearchTree* newBST = new BinarySearchTree(value);
            left_ = newBST;
        }
    }
}

int BinarySearchTree::GetNodeCount() {
    int count = 0;
    if (left_) {
        count += left_->GetNodeCount();
    }
    if (right_) {
        count += right_->GetNodeCount();
    }
    return count + 1;
}

void BinarySearchTree::PrintValues() {
    if (left_) {
        left_->PrintValues();
    }

    std::cout << value_ << std::endl;

    if (right_) {
        right_->PrintValues();
    }
}

void BinarySearchTree::DeleteTree() {
    if (left_) {
        left_->DeleteTree();
    }
    if (right_) {
        right_->DeleteTree();
    }
    delete this;
}

bool BinarySearchTree::IsInTree(int value) {
    bool inTree = false;
    
    if (value_ == value) {
        return true;
    }
    else {
        if (left_) {
            inTree = left_->IsInTree(value);
        }
        if (right_ && !inTree) {
            inTree = right_->IsInTree(value);
        }
        return inTree;
    }
}

int BinarySearchTree::GetHeight() {
    if (left_ && right_) {
        return std::max(left_->GetHeight(), right_->GetHeight()) + 1;
    }
    else {
        if (left_) {
            return left_->GetHeight() + 1;
        }
        else if (right_) {
            return right_->GetHeight() + 1;
        }
        else {
            return 1;
        }
    }
}

int BinarySearchTree::GetMax() {
    if (right_) {
        return right_->GetMax();
    }
    else {
        return value_;
    }
}

int BinarySearchTree::GetMin() {
    if (left_) {
        return left_->GetMin();
    }
    else {
        return value_;
    }
}

bool BinarySearchTree::IsBinarySearchTree() {
    bool isTree = true;
    if (left_ && right_) {
        isTree = (value_ > left_->value_) &&
                 (value_ < right_->value_) &&
                 left_->IsBinarySearchTree() &&
                 right_->IsBinarySearchTree();
    }
    else {
        if (left_) {
            isTree = (value_ > left_->value_) &&
                     (left_->IsBinarySearchTree());
        }
        else if (right_) {
            isTree = (value_ < right_->value_) &&
                     (right_->IsBinarySearchTree());
        }
    }
    return isTree;
}

void BinarySearchTree::DeleteValue(int value) {
    if (value_ == value) {
        ShiftTree(this);
    }
    else {
        if (left_) {
            left_->DeleteValue(value);
        }
        if (right_) {
            right_->DeleteValue(value);
        }
    }
}

void BinarySearchTree::ShiftTree(BinarySearchTree* bst) {
    if (left_) {
        int newValue = left_->GetMax();
        left_->RemoveChild(newValue);
        value_ = newValue;
    }
    else if (right_) {
        int newValue = right_->GetMin();
        right_->RemoveChild(newValue);
        value_ = newValue;
    }
    else {
        RemoveChild(value_);
    }
}

void BinarySearchTree::RemoveChild(int value) {
    if (left_) {
        if (left_->value_ == value) {
            delete left_;
            left_ = nullptr;
        }
        else {
            left_->RemoveChild(value);
        }
    }
    if (right_) {
        if (right_->value_ == value) {
            delete right_;
            right_ = nullptr;
        }
        else {
            right_->RemoveChild(value);
        }
    }
}

void BinarySearchTree::PrintValuesByLevel() {
    std::queue<BinarySearchTree*> bstQ;

    bstQ.push(this);

    BinarySearchTree* currentBST;

    while(!bstQ.empty()) {
        currentBST = bstQ.front();
        std::cout << currentBST->value_ << std::endl;;
        bstQ.pop();

        if (currentBST->left_) {
            bstQ.push(currentBST->left_);
        }
        if (currentBST->right_) {
            bstQ.push(currentBST->right_);
        }
    }
}

#endif
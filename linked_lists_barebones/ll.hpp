#ifndef __ll_hpp__
#define __ll_hpp__

class LinkedList {
    public:
        struct Node {
            int value;
            Node* next;
        };
                
        LinkedList(int value);
        ~LinkedList();
        int size();
        bool empty();
        int value_at(int index);
        Node* push_front(int value);
        int pop_front();
        Node* push_back(int value);
        int pop_back();
        int front();
        int back();
        Node* insert(int index, int value);
        Node* erase(int index);
        int value_n_from_end(int n);
        Node* reverse();
        Node* remove_value(int index);
        
        Node* get_head();

    private:
        Node* m_head;
};

#endif
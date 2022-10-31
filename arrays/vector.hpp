#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
    public:
        Vector(int s);
        ~Vector();
        int size();
        int capacity();
        bool is_empty();
        int at(int index);
        int* push(int value);
        int* insert(int index, int item);
        int* prepend(int value);
        int pop();
        int* del(int index);
        int* rem(int value);
        int find(int value);

    private:
        int* m_elems;
        int m_size;
        int m_capacity;
        
        void resize(int new_capacity);
};

#endif
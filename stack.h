#ifndef ARRAY_H
#define ARRAY_H
#include "linked_list.h"
// #include "linked_list.cpp"
template <class T>
class Stack{
    private:
        size_t capacity;
        size_t size;
        T *stack;
        T *top;

    public:
        // Constructors
        Stack();
        Stack(int capacity);
        Stack(int size, T arr[]);
        Stack(int capacity, const LinkedList<T>& ll);
        Stack(const Stack<T> &stack); // Copy Constructor

        // Accessors (Getters)
        T peek() const;
        int getSize() const;
        int getCapacity() const;

        // Enquiry Functions
        bool isEmpty() const;

        // Mutators (Setters)
        T pop();

        // // Accessors (Getters)
        // T* getArray() const;
        // int getLength() const;
        // int getSize() const;
        // T get(int index) const;

        // Facilitators
        void display() const;
        // int append(T element);
        // void insert(int index, T element);
        // T del(int index);
        // int remove(T element);
        // T pop();
        // int search(T element, bool improvised=true) const;
        // int bin_search(T element) const;
        // T max() const;
        // T min() const;
        // void reverse();
        // void l_shift();
        // void r_shift();
        // void l_rotate();
        // void r_rotate();
        // // sortings

        // // Operator Overloadings
        // T& operator[](int index) const;
        // template<class U>
        // friend std::ostream &operator<<(std::ostream &out, const Array<U>& arr);

        // // Destructors
        // ~Array();
};
#endif
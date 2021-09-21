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
        void push(T ele);

        // Facilitators
        void display() const;

        // Operator Overloads
        template<class U>
        friend std::ostream &operator<<(std::ostream &cout, const Stack<U> &stack);


        // Destructors
        ~Stack();
};
#endif
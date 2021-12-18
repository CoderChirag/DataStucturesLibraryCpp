#include<iostream>
#include "linked_list.h"
#include "stack.h"

// Constructors
template<class T>
Stack<T>::Stack(): capacity{10}, size{0}{
    this->stack = new T[10];
    top = stack;
}
template<class T>
Stack<T>::Stack(int capacity) : capacity{capacity > 0 ? static_cast<size_t>(capacity) : 10}, size{0}{
    this->stack = new T[this->capacity];
    top = stack;
}
template <class T>
Stack<T>::Stack(int size, T arr[]) : capacity{size > 0 ? static_cast<size_t>(size) : 10}, size{size > 0 ? static_cast<size_t>(size) : 0}{
    stack = new T[capacity];
    for (int i = 0; i < size; i++){
        stack[i] = arr[i];
    }
    top = stack + this->size - 1;
}
template<class T>
Stack<T>::Stack(int capacity, const LinkedList<T>& ll) : capacity{capacity > 0 ? static_cast<size_t>(capacity) : 10}, size{static_cast<size_t>(ll.size())}{
    stack = new T[capacity];
    for (int i = 0; i < ll.size(); i++){
        stack[i] = ll.at(i);
    }
    top = stack + this->size - 1;
}
template<class T>
Stack<T>::Stack(const Stack<T> &stack){
    size = stack.size;
    capacity = stack.capacity;
    this->stack = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        this->stack[i] = stack.stack[i];
    }
    top = this->stack + this->size - 1;
}

// Accessors
template<class T>
T Stack<T>::peek() const{
    return *top;
}
template<class T>
int Stack<T>::getSize() const{
    return size;
}
template<class T>
int Stack<T>::getCapacity() const{
    return capacity;
}

// Enquiry Functions
template<class T>
bool Stack<T>::isEmpty() const{
    return size == 0;
}

// Mutators
template<class T>
T Stack<T>::pop(){
    if(size == 0) {
        throw std::runtime_error(std::string("Stack already empty"));
    }
    T ele = stack[size - 1];
    stack[size - 1] = static_cast<T>(0);
    size--;
    top = stack + size - 1;
    return ele;
}
template<class T>
void Stack<T>::push(T ele){
    if(size == capacity){
        T *temp = new T[size * 2];
        for (int i = 0; i < size; i++){
            temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
        capacity *= 2;
    }
    stack[size] = ele;
    size++;
    top = stack + size - 1;
}

// Facilitators
template<class T>
void Stack<T>::display() const{
    for (int i = size-1; i >= 0; i--){
        std::cout << stack[i] << std::endl;
    }
}

// Operator Overloads
template<class T>
std::ostream &operator<<(std::ostream& cout, const Stack<T>& stack){
    for (int i = stack.size - 1; i >= 0; i--){
        cout << stack.stack[i] << std::endl;
    }
    return cout;
}

// Destructors
template<class T>
Stack<T>::~Stack(){
    delete[] stack;
}
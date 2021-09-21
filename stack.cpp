#include<iostream>
#include "linked_list.h"
#include "stack.h"

// Constructors
template<class T>
Stack<T>::Stack(): capacity{10}, size{0}{
    this->stack = new T[10];
}
template<class T>
Stack<T>::Stack(int capacity) : capacity{capacity > 0 ? static_cast<size_t>(capacity) : 10}, size{0}{
    this->stack = new T[this->capacity];
}
template <class T>
Stack<T>::Stack(int size, T arr[]) : capacity{size > 0 ? static_cast<size_t>(size) : 10}, size{size > 0 ? static_cast<size_t>(size) : 0}{
    stack = new T[capacity];
    for (int i = 0; i < size; i++){
        stack[i] = arr[i];
    }
}
template<class T>
Stack<T>::Stack(int capacity, const LinkedList<T>& ll) : capacity{capacity > 0 ? static_cast<size_t>(capacity) : 10}, size{static_cast<size_t>(ll.size())}{
    stack = new T[capacity];
    for (int i = 0; i < ll.size(); i++){
        stack[i] = ll.at(i);
    }
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
}

// Facilitators
template<class T>
void Stack<T>::display() const{
    for (int i = 0; i < size; i++){
        std::cout << stack[i] << " ";
    }
}
#include<iostream>
#include<stdexcept>
#include"linked_list.h"

// Constructors
template<class T>
LinkedList<T>::LinkedList(){
    first = new Node<T>;
    first->next = NULL;
    last = first;
    length = 0;
}
template<class T>
LinkedList<T>::LinkedList(int n, const T arr[]): LinkedList{}{
    struct Node<T> *p = first;
    for (int i = 0; i < n; i++){
        p->data = arr[i];
        length++;
        last = p;
        if(i != n-1){
            struct Node<T> *next = new Node<T>;
            p->next = next;
            p = next;
        }else{
            p->next = NULL;
        }
    }
}


// Facilitators
template<class T>
void LinkedList<T>::display(){
    struct Node<T> *p = first;
    if(length > 0){
        while(p != NULL){
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }else{
        std::cout << "" << std::endl;
    }
}
template<class T>
void LinkedList<T>::prepend(T data){
    if(length == 0){
        first->data = data;
        length++;
    }else{
        struct Node<T> *first = new Node<T>;
        first->data = data;
        first->next = this->first;
        this->first = first;
        length++;
    }
}
template<class T>
void LinkedList<T>::append(T data){
    if(length == 0){
        first->data = data;
        length++;
    }else{
        struct Node<T> *last = new Node<T>;
        last->data = data;
        last->next = NULL;
        this->last->next = last;
        this->last = last;
        length++;
    }
}


// Operator Overloads
template<class T>
std::ostream& operator<<(std::ostream& cout, const LinkedList<T>& ll){
    struct Node<T> *p = ll.first;
    if(ll.length > 0){
        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << std::endl;
    }else{
        cout << "" << std::endl;
    }
    return cout;
}
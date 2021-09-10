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


// Accessors (Getter Functions)
template<class T>
int LinkedList<T>::size(){
    return length;
}


// Mutators (Setter Functions)
template<class T>
void LinkedList<T>::insert(int index, T data){
    if(index > length || index < 0){
        throw std::runtime_error(std::string("Index out of bound exception"));
    }else if(index == 0){
        prepend(data);
    }else if(index == length){
        append(data);
    }else{
        struct Node<T> *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        struct Node<T> *temp = p->next;
        struct Node<T> *newEle = new Node<T>;
        p->next = newEle;
        newEle->data = data;
        newEle->next = temp;
        length++;
    }

}
template<class T>
T LinkedList<T>::remove(int index){
    T data;
    if(index >= length || index < 0){
        throw std::runtime_error(std::string("Index out of bound exception"));
    }else if(index == 0){
        if(length == 1){
            data = first->data;
            delete first;
            first = new Node<T>;
            first->next = NULL;
            last = first;
            length--;
        }else{
            struct Node<T> *temp = first->next;
            data = first->data;
            delete first;
            first = temp;
            length--;
        }
    }else{
        struct Node<T> *p = first;
        for (int i = 0; i < index - 1; i++){
            p = p->next;
        }
        struct Node<T> *temp = p->next->next;
        data = p->next->data;
        delete p->next;
        p->next = temp;
        length--;
        if(p->next == NULL){
            last = p;
        }
    }
    return data;
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
template<class T>
T LinkedList<T>::pop_front(){
    if(length == 0){
        throw std::runtime_error(std::string("The Linked List is already empty"));
    }else if(length == 1){
        T data = first->data;
        delete first;
        first = new Node<T>;
        first->next = NULL;
        last = first;
        length--;
        return data;
    }else{
        T data = first->data;
        struct Node<T> *p = first;
        first = first->next;
        length--;
        delete p;
        return data;
    }
}
template<class T>
T LinkedList<T>::pop_back(){
    if(length == 0){
        throw std::runtime_error(std::string("The Linked List is already empty."));
    }else if(length == 1){
        T data = first->data;
        delete first;
        first = new Node<T>;
        first->next = NULL;
        last = first;
        length--;
        return data;
    }else{
        struct Node<T> *p = first;
        while(p->next->next != NULL){
            p = p->next;
        }
        T data = last->data;
        delete last;
        last = p;
        last->next = NULL;
        length--;
        return data;
    }
}


// Enquiry Functions
template<class T>
bool LinkedList<T>::isEmpty(){
    return length > 0;
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


// Destructor
template<class T>
LinkedList<T>::~LinkedList(){
    while(first->next != NULL){
        struct Node<T> *temp = first->next;
        delete first;
        first = temp;
    }
    delete first;
}
#include<iostream>
#include<stdexcept>
#include"linked_list.h"

// Constructors
template<class T>
LinkedList<T>::LinkedList(){
    first = new linked_list::Node<T>;
    first->next = NULL;
    tail = first;
    length = 0;
}
template<class T>
LinkedList<T>::LinkedList(int n, const T arr[]): LinkedList{}{
    struct linked_list::Node<T> *p = first;
    for (int i = 0; i < n; i++){
        p->data = arr[i];
        length++;
        tail = p;
        if(i != n-1){
            struct linked_list::Node<T> *next = new linked_list::Node<T>;
            p->next = next;
            p = next;
        }else{
            p->next = NULL;
        }
    }
}


// Accessors (Getter Functions)
template<class T>
int LinkedList<T>::size() const{
    return length;
}
template<class T>
T LinkedList<T>::at(int index) const{
    if(index < 0 || index >= length){
        throw std::runtime_error(std::string("Index out of bound exception"));
    }
    struct linked_list::Node<T> *p = first;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    return p->data;
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
        struct linked_list::Node<T> *p = first;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        struct linked_list::Node<T> *temp = p->next;
        struct linked_list::Node<T> *newEle = new linked_list::Node<T>;
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
            first = new linked_list::Node<T>;
            first->next = NULL;
            tail = first;
            length--;
        }else{
            struct linked_list::Node<T> *temp = first->next;
            data = first->data;
            delete first;
            first = temp;
            length--;
        }
    }else{
        struct linked_list::Node<T> *p = first;
        for (int i = 0; i < index - 1; i++){
            p = p->next;
        }
        struct linked_list::Node<T> *temp = p->next->next;
        data = p->next->data;
        delete p->next;
        p->next = temp;
        length--;
        if(p->next == NULL){
            tail = p;
        }
    }
    return data;
}
template<class T>
void LinkedList<T>::prepend(T data){
    if(length == 0){
        first->data = data;
        length++;
    }else{
        struct linked_list::Node<T> *first = new linked_list::Node<T>;
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
        struct linked_list::Node<T> *tail = new linked_list::Node<T>;
        tail->data = data;
        tail->next = NULL;
        this->tail->next = tail;
        this->tail = tail;
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
        first = new linked_list::Node<T>;
        first->next = NULL;
        tail = first;
        length--;
        return data;
    }else{
        T data = first->data;
        struct linked_list::Node<T> *p = first;
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
        first = new linked_list::Node<T>;
        first->next = NULL;
        tail = first;
        length--;
        return data;
    }else{
        struct linked_list::Node<T> *p = first;
        while(p->next->next != NULL){
            p = p->next;
        }
        T data = tail->data;
        delete tail;
        tail = p;
        tail->next = NULL;
        length--;
        return data;
    }
}


// Facilitators
template<class T>
void LinkedList<T>::display() const{
    struct linked_list::Node<T> *p = first;
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
void LinkedList<T>::reverse(){
    if(length == 0){
        return;
    }
    struct linked_list::Node<T> *p = first;
    struct linked_list::Node<T> *q = NULL;
    while(p != NULL){
        struct linked_list::Node<T> *temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    struct linked_list::Node<T> *temp = first;
    first = temp;
    first = tail;
    tail = temp;
}
template<class T>
void LinkedList<T>::concat(LinkedList& ll){
    if(ll.length == 0){
        return;
    }
    if(ll.first == this->first){
        throw std::runtime_error(std::string("Cannot concatente to itself"));
    }
    struct linked_list::Node<T> *p = ll.first;
    if(length == 0){
        tail->data = p->data;
        p = p->next;
    }
    while(p != NULL){
        tail->next = new linked_list::Node<T>;
        tail->next->data = p->data;
        tail->next->next = p->next;
        tail = tail->next;
        p = p->next;
    }
    length += ll.length;
}



// Enquiry Functions
template<class T>
bool LinkedList<T>::isEmpty() const{
    return length > 0;
}


// Operator Overloads
template<class T>
T& LinkedList<T>::operator[](int index) const{
    if(index < 0 || index >= length){
        throw std::runtime_error(std::string("Index out of bound exception"));
    }
    struct linked_list::Node<T> *p = first;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    return p->data;
}
template<class T>
std::ostream& operator<<(std::ostream& cout, const LinkedList<T>& ll){
    struct linked_list::Node<T> *p = ll.first;
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
        struct linked_list::Node<T> *temp = first->next;
        delete first;
        first = temp;
    }
    delete first;
}
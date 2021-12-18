#include <iostream>
#include<stdexcept>
#include "queue.h"

template<class T>
Queue<T>::Queue(): length{0}{
    front = NULL;
    rear = NULL;
}

// Constructors
template <class T>
Queue<T>::Queue(int length, const T arr[]): Queue{}{
    for (int i = 0; i < length; i++){
        if(front == NULL){
            front = new queue_node::Node<T>;
            front->data = arr[i];
            front->next = NULL;
            rear = front;
        }else{
            rear->next = new queue_node::Node<T>;
            rear = rear->next;
            rear->data = arr[i];
            rear->next = NULL;
        }
        this->length++;
    }
}

// Accessors (Getter Functions)
template<class T>
int Queue<T>::size() const{
    return length;
}
template<class T>
T Queue<T>::getFront() const{
    if(!front){
        throw std::runtime_error(std::string("Queue is empty"));
    }
    return front->data;
}
template<class T>
T Queue<T>::getRear() const{
    if(!rear){
        throw std::runtime_error(std::string("Queue is empty"));
    }
    return rear->data;
}

// Mutators (Setter Functions)
template<class T>
void Queue<T>::enqueue(T data){
    if(rear == NULL){
        front = new queue_node::Node<T>;
        front->data = data;
        front->next = NULL;
        rear = front;
    }else{
        rear->next = new queue_node::Node<T>;
        rear = rear->next;
        rear->data = data;
        rear->next = NULL;
    }
    length++;
}

template<class T>
T Queue<T>::dequeue(){
    if(front == NULL){
        throw std::runtime_error(std::string("Queue is empty"));
    }

    struct queue_node::Node<T>* Node = front;
    T data = front->data;
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    length--;
    delete Node;
    return data;
}

// Facilitators
template<class T>
void Queue<T>::display() const{
    struct queue_node::Node<T> *i = front;
    while (i != NULL){
        std::cout << i->data << " ";
        i = i->next;
    }
    std::cout << std::endl;
}

// Enquiry Funnctions
template<class T>
bool Queue<T>::isEmpty() const{
    if(front == NULL){
        return true;
    }
    return false;
}

// Operator Overloads
template<class T>
std::ostream &operator<<(std::ostream &cout, const Queue<T> &q){
    struct queue_node::Node<T> *i = q.front;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    cout << std::endl;
    return cout;
}

// Destructor
template<class T>
Queue<T>::~Queue(){
    while(front != NULL){
        struct queue_node::Node<T> *Node = front;
        front = front->next;
        delete Node;
    }
    rear = NULL;
}
#ifndef LINKED_LIST
#define LINKED_LIST
template<class T>
struct Node{
    T data;
    struct Node *next;
};
template<class T>
class LinkedList{
    private:
        struct Node<T> *first;
        struct Node<T> *last;
        int length;
    public:
        // Constructors
        LinkedList();
        LinkedList(int n, const T arr[]);

        // Facilitators
        void display();
        void prepend(T data);
        void append(T data);

        // Operator Overloads
        template<class U>
        friend std::ostream &operator<<(std::ostream &cout, const LinkedList<U> &ll);
};
#endif
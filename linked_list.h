#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class T>
struct Node{
    T data;
    struct Node *next;
};
template<class T>
class LinkedList{
    private:
        struct Node<T> *first;
        struct Node<T> *tail;
        int length;
    public:
        // Constructors
        LinkedList();
        LinkedList(int n, const T arr[]);

        // Accessors (Getter Functions)
        int size() const;
        T at(int index) const;

        // Mutators (Setter Functions)
        void insert(int index, T data);
        T remove(int index);
        void prepend(T data);
        void append(T data);
        T pop_front();
        T pop_back();

        // Facilitators
        void display() const;
        void reverse();
        void concat(LinkedList& ll);

        // Enquiry Functions
        bool isEmpty() const;

        // Operator Overloads
        T& operator[](int index) const;
        template <class U>
        friend std::ostream &operator<<(std::ostream &cout, const LinkedList<U> &ll);

        // Destructor
        ~LinkedList();
};
#endif
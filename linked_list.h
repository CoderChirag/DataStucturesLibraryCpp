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

        // Accessors (Getter Functions)
        int size();

        // Mutators (Setter Functions)
        void insert(int index, T data);
        T remove(int index);

        // Facilitators
        void display();
        void prepend(T data);
        void append(T data);
        T pop_front();
        T pop_back();

        // Enquiry Functions
        bool isEmpty();

        // Operator Overloads
        template<class U>
        friend std::ostream &operator<<(std::ostream &cout, const LinkedList<U> &ll);

        // Destructor
        ~LinkedList();
};
#endif
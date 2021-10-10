#ifndef QUEUE_H
#define QUEUE_H
template<class T>
struct Node{
    T data;
    struct Node *next;
};
template<class T>
class Queue{
    private:
        struct Node<T> *front;
        struct Node<T> *rear;
        int length;
    public:
        // Constructors
        Queue();
        Queue(int length, const T arr[]);

        // Accessors (Getter Functions)
        int size() const;
        T getFront() const;
        T getRear() const;

        // Mutators (Setter Functions)
        void enqueue(T data);
        T dequeue();

        // Facilitators
        void display() const;

        // Enquiry Functions
        bool isEmpty() const;

        // Operator Overloads
        template <class U>
        friend std::ostream &operator<<(std::ostream &cout, const Queue<U> &q);

        // Destructor
        ~Queue();
};
#endif
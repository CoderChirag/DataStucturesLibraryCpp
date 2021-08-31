#ifndef ARRAY_H
#define ARRAY_H
#include<exception>
#include<string>
class ArrayException : public std::exception{
    private:
        std::string error_msg{};
    public:
        ArrayException(std::string error);
        const char* what() const noexcept override;
};
template <class T>
class Array{
    private:
        size_t length;
        size_t size; // size refers to the total capacity of the array
        T *arr;

    public:
        // Constructors
        Array();
        Array(int size);
        Array(int size, T arr[]);
        Array(const Array &array); // Copy Constructor

        // Mutators (Setters)
        void set(int index, T element);

        // Accessors (Getters)
        T* getArray() const;
        int getLength() const;
        int getSize() const;
        T get(int index) const;

        // Facilitators
        void display() const;
        int append(T element);
        void insert(int index, T element);
        T del(int index);
        int remove(T element);
        T pop();
        int search(T element, bool improvised=true) const;
        int bin_search(T element) const;
        T max() const;
        T min() const;
        // T max();
        // T min();
        // T sum();
        // max
        // min
        // sum
        // reverse
        // shift / rotate
        // sortings



        // Destructors
        ~Array();
};
#endif
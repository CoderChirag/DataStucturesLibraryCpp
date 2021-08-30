#include<iostream>
#include<exception>
#include<string>
#include "array.h"
using namespace std;
// Exception Class
ArrayException::ArrayException(string error): error_msg{error}{}
const char* ArrayException::what() const noexcept{
    return error_msg.c_str();
}


// Constructors
template<class T>
Array<T>::Array(): length{0}, size{10}{
    this->arr = new T[size]{0};
}
template<class T>
Array<T>::Array(int size): length{static_cast<size_t>(size)}, size{static_cast<size_t>(size)} {
    this->arr = new T[size]{0};
}
template<class T>
Array<T>::Array(int size, T arr[]): Array{size}{
    for (int i = 0; i < size; i++){
        this->arr[i] = arr[i];
    }
}
template<class T>
Array<T>::Array(const Array &array): Array{static_cast<int>(array.size), array.get()}{
} // Copy Constructor



// Mutators (Setters)



// Accessors (Getters)
template<class T>
T* Array<T>::getArray() const{
    return arr;
}
template<class T>
int Array<T>::getLength() const{
    return length;
}
template<class T>
int Array<T>::getSize() const{
    return size;
}



// Facilitators
template<class T>
void Array<T>::display() const{
    // Time Complexity -> O(n)
    for (int i = 0; i<length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
template<class T>
int Array<T>::append(T x){
    // Time Complexity
    // if size=length -> O(n)
    // else -> O(1)
    if(size == length){
        size+=10;
        T *newArr = new T[size]{0};
        for (int i = 0; i < length; i++){
            newArr[i] = arr[i];
        }
        newArr[length] = x;
        length++;
        delete[] arr;
        arr = newArr;
    }else{
        arr[length] = x;
        length++;
    }

    return length;
}
template<class T>
void Array<T>::insert(int index, T x){
    // Time Complexity -> O(n)
    try{
        if(index > length){
            throw ArrayException("Index cannot be greater than length while inserting in array");
        }
        if(length == size){
            size += 10;
            T *newArr = new T[size]{0};
            for (int i = 0; i < index; i++){
                newArr[i] = arr[i];
            }
            for (int i = length; i > index; i--){
                newArr[i] = arr[i - 1];
            }
            newArr[index] = x;
            length++;
            delete[] arr;
            arr = newArr;
        }else{
            for (int i = length; i > index; i--){
                arr[i] = arr[i - 1];
            }
            arr[index] = x;
            length++;
        }
    }catch(const ArrayException& e){
        cout << "Error: " << e.what() << endl;
    }catch(...){
        cout << "Error: Something Went Wrong";
    }
}
template<class T>
T Array<T>::del(int index){
    // Time Complexity -> O(n)
    if(index >= length){
        throw ArrayException("Index cannot be greater than length");
    }

    T x = arr[index];
    for (int i = index; i < length-1;i++){
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0;
    length--;
    return x;
}
template<class T>
int Array<T>::remove(T x){
    // Time Complexity -> O(n)
    bool flag = false;
    int index = 0;
    for (; index < length; index++){
        if(arr[index] == x){
            flag = true;
            break;
        }
    }
    for (int i = index; i < length-1; i++){
        arr[i] = arr[i + 1];
    }
    if(flag){
        arr[length - 1] = 0;
        length--;
        return index;
    }else{
        return -1;
    }
}




// Destructors 
template<class T>
Array<T>::~Array(){
    delete[] arr;
}



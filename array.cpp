#include<iostream>
#include<exception>
#include<typeinfo>
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
Array<T>::Array(int size): length{size > 0 ? static_cast<size_t>(size) : 0}, size{size > 0 ? static_cast<size_t>(size) : 0} {
    this->arr = new T[size]{0};
}
template<class T>
Array<T>::Array(int size, T arr[]): Array{size > 0 ? size : 0}{
    for (int i = 0; i < size; i++){
        this->arr[i] = arr[i];
    }
}
template<class T>
Array<T>::Array(const Array &array): Array{static_cast<int>(array.size), array.get()}{
} // Copy Constructor



// Mutators (Setters)
template<class T>
void Array<T>::set(int index, T element){
    // Time Complexity -> O(1)
    if(index <= 0 || index >= length){
        throw ArrayException("Error: Index out of bound Exception");
    }

    arr[index] = element;
}


// Accessors (Getters)
template<class T>
T* Array<T>::getArray() const{
    // Time Complexity -> O(n)
    T* newArr = new T[length];
    for (int i = 0; i < length; i++){
        newArr[i] = arr[i];
    }

    return newArr;
}
template<class T>
int Array<T>::getLength() const{
    // Time Complexity -> O(1)
    return length;
}
template<class T>
int Array<T>::getSize() const{
    // Time Complexity -> O(1)
    return size;
}
template<class T>
T Array<T>::get(int index) const{
    // Time Complexity -> O(1)
    if(index <= 0 || index >= length){
        throw ArrayException("Error: Index out of bound exception");
    }

    return arr[index];
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
int Array<T>::append(T element){
    // Time Complexity
    // if size=length -> O(n)
    // else -> O(1)
    if(size == length){
        size+=10;
        T *newArr = new T[size]{0};
        for (int i = 0; i < length; i++){
            newArr[i] = arr[i];
        }
        newArr[length] = element;
        length++;
        delete[] arr;
        arr = newArr;
    }else{
        arr[length] = element;
        length++;
    }

    return length;
}
template<class T>
void Array<T>::insert(int index, T element){
    // Time Complexity -> O(n)
    if(index <= 0 || index >= length){
        throw ArrayException("Error: Index out of bound Exception");
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
        newArr[index] = element;
        length++;
        delete[] arr;
        arr = newArr;
    }else{
        for (int i = length; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        length++;
    }

}
template<class T>
T Array<T>::del(int index){
    // Time Complexity -> O(n)
    if(index <= 0 || index >= length){
        throw ArrayException("Error: Index out of bound Exception");
    }

    T element = arr[index];
    for (int i = index; i < length-1;i++){
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0;
    length--;
    return element;
}
template<class T>
int Array<T>::remove(T element){
    // Time Complexity -> O(n)
    bool flag = false;
    int index = 0;
    for (; index < length; index++){
        if(arr[index] == element){
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
template<class T>
T Array<T>::pop(){
    // Time Complexity -> O(1);
    if(length == 0){
        throw ArrayException("Error: Index out of bound exception");
    }

    T ele = arr[length - 1];
    arr[length - 1] = 0;
    length--;
    return ele;
}
template<class T>
int Array<T>::search(T element, bool improvised) const{
    // Time Complexity -> O(n)
    for (int i = 0; i < length; i++){
        if(element == arr[i]){
            if(improvised && i != 0){
                T temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
            return i;
        }
    }

    return -1;
}
template<class T>
int Array<T>::bin_search(T element) const{
    // Time complexity -> O(logn)
    int l = 0;
    int r = length - 1;
    while (l<=r){
        int mid = (l + r) / 2;
        if(arr[mid] == element){
            return mid;
        }else if(element > arr[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return -1; 
}
template<class T>
T Array<T>::max() const{
    // Time Complexity -> O(n)
    if(length == 0){
        throw ArrayException("Error: Array is empty");
    }

    T max = arr[0];
    for (int i = 0; i < length; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}
template<class T>
T Array<T>::min() const{
    // Time Complexity -> O(n)
    if(length == 0)
        throw ArrayException("Error: Array is empty");

    T min = arr[0];
    for (int i = 0; i < length; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}
template<class T>
void Array<T>::reverse(){
    // Time Complexity -> O(n)
    for (int i = 0, j = length - 1; i < j; i++, j--){
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
template<class T>
void Array<T>::l_shift(){
    try{
        for (int i = 1; i < length; i++){
            arr[i - 1] = arr[i];
        }
        arr[length - 1] = 0;
    }catch(exception e){
        cerr << e.what() << endl;
    }
}
template<class T>
void Array<T>::r_shift(){
    try{
        for (int i = length-1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = 0;
    }catch(exception e){
        cerr << e.what() << endl;
    }
}
template<class T>
void Array<T>::l_rotate(){
    try{
        T temp = arr[0];
        for (int i = 1; i < length; i++){
            arr[i - 1] = arr[i];
        }
        arr[length - 1] = temp;
    }catch(exception e){
        cerr << e.what() << endl;
    }
}
template<class T>
void Array<T>::r_rotate(){
    try{
        T temp = arr[length - 1];
        for (int i = length-1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }catch(exception e){
        cerr << e.what() << endl;
    }
}




// Destructors 
template<class T>
Array<T>::~Array(){
    delete[] arr;
}
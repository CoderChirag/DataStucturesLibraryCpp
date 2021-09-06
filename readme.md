# My Data Structures Library

This library is created for using various Data Structures easily in C++.

## Array

-   Implements the resizable dynamic arrays.
-   Template class, can be used for any data type

### How to use

1.  Place the files `array.h` and `array.cpp` inside the root folder of your project
2.  Example code to use `Array`:

        // main.cpp
        #include<iostream>
        #include"array.h"
        #include"array.cpp"
        using namespace std;

            int main(){
                Array<int> arr{5};

                arr.append(1);
                arr.append(5);
                arr.append(8);

                cout << arr.getLength() <<endl;
                cout << arr.getSize() <<endl;

                cout << arr.get(5);
                cout << arr.set(1, 5);

                arr.display();
            }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

The Array class maintains an array, with its 2 properties:- **length** and **size**.

**size** -> It is the maximum capacity of the array. When the maximum capacity is reached, the array class automatically resizes the array. By default, it's value is **10**.

**length** -> It is the actual number of elements present in the array at any given time.

#### 1. Constructors

-   `Array()` -> Initializes an array with **length = 0** and **size = 10**.
-   `Array(int size)` -> Initializes an array with the given **size**.
-   `Array(int size, T arr[])` -> Initializes an array with the given **size** and fills it with the given **array**.
-   `Array(const Array<T>& array)` -> **_Copy Constructor_**. Initializes the Array object by copying the array from the given Array object.

#### 2. Mutators (Setter Methods)

-   `void set(int index, T x)` -> Sets the value **x** at the specified **index** of the array.

#### 3. Accessors (Getter Methods)

-   `T* getArray() const` -> Returns the pointer to the complete array.
-   `int getLength() const` -> Returns the **length** of the array.
-   `int getSize() const` -> Returns the **size (current maximum capacity)** of the array.
-   `T get(int index) const` -> Returns the **value** at the specified index.

#### 4. Facilitators

-   `void display() const` -> Prints space separated all the members of the array.
-   `int append(T x)` -> Appends the given element at the last of the array and returns the **length** of the new array.
-   `void insert(int index, T x)` -> Inserts the given element at the specified index in the array.
-   `T del(int index)` -> Deletes the element at the specified index from the array and returns the **deleted element**.
-   `int remove(T x)` -> Removes the given element from the array and returns the **index** on which it was previously present. Returns **-1** if the element was not found.
-   `T pop()` -> Removes the last element from the array and returns the element popped out.
-   `int search(T element, bool improvised=true)` -> Performs the linear search for the element specified and returns the index of the element. If **improvised** is `true`, it will swap the found element with the previous elements of the array to improve the efficiency in the next search. To prevent it set **improvised** to `false`. By default, improvised is set to `true`.
-   `int bin_search(T element)` -> Performs binary search on the array for the specified value and returns the **index** of it. Time complexity is of O(logN).
-   `T max()` -> Returns the largest element of the array.
-   `T min()` -> Returns the smallest element of the array.
-   `void reverse()` -> Reverses the array.
-   `void l_shift()` -> Left shifts all the elements of the array, and the **rightmost element becomes 0**.
-   `void r_shift()` -> Right shifts all the elements of the array, and the **leftmost element becomes 0**.
-   `void l_rotate()` -> Rotates all the elements of the array to the left, so that the element which was **previously the first element** in the array, **becomes the rightmost element** after rotation.
-   `void r_rotate()` -> Rotates all the elements of the array to the right, so that the element which was **previously the rightmost element** in the array, **becomes the first element** after rotation.

#### 5. Operator Overloads

-   Subscript Operator(`[]`) -> Can be used to **access** and **assign** the value.
-   Extraction Operator(`<<`) -> For printing the whole array. Eg. `cout << arr;` **output** - `[1, 2, 3, 4, 5]`

# Array - A Library for using resizable arrays

## 1. How to use

1.  Place the files `array.h` and `array.cpp` inside the root folder of your project
2.  Example code to use the library:

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

## 2. Documentation

The Array class maintains an array, with its 2 properties:- **length** and **size**.
**size** -> It is the maximum capacity of the array. When the maximum capacity is reached, the array class automatically resizes the array. By default, it's value is **10**.
**length** -> It is the actual number of elements present in the array at any given time.

### 1. Constructors

-   `Array()` -> Initializes an array with **length = 0** and **size = 10**.
-   `Array(int size)` -> Initializes an array with the given **size**.
-   `Array(int size, T arr[])` -> Initializes an array with the given **size** and fills it with the given **array**.

### 2. Mutators (Setter Methods)

-   `int set(int index, T x)` -> Sets the value **x** at the specified **index** of the array. Returns **0** if index is greater than length. If it is successful, returns **1**.

### 3. Accessors (Getter Methods)

-   `T* getArray() const` -> Returns the complete array.
-   `int getLength() const` -> Returns the **length** of the array.
-   `int getSize() const` -> Returns the **size (current maximum capacity)** of the array.
-   `T get(int index) const` -> Returns the **value** at the specified index.

### 4. Facilitators

-   `void display() const` -> Prints space separated all the members of the array.
-   `int append(T x)` -> Appends the given element at the last of the array and returns the **length** of the new array.
-   `void insert(int index, T x)` -> Inserts the given element at the specified index in the array.
-   `T del(int index)` -> Deletes the element at the specified index from the array and returns the **deleted element**.
-   `int remove(T x)` -> Removes the given element from the array and returns the **index** on which it was previously present. Returns **-1** if the element was not found.

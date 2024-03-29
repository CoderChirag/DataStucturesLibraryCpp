# Data Structures Library : STL-like C++ library for implementing various Data Structures

This library is created for using various Data Structures easily in C++.

## Array

-   Implements the resizable dynamic arrays.
-   Built on template classes, so can be used for any data type

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
-   Insertion Operator(`<<`) -> For printing the whole array. Eg. `cout << arr;` **output** - `[1, 2, 3, 4, 5]`

## Matrix

-   Implements the different types of matrices.

### How to use

1.  Place the files `matrix.h` and `matrix.cpp` inside the root folder of your project
2.  Example code to use `Matrix`:

        // main.cpp
        #include<iostream>
        #include"matrix.h"
        #include"matrix.cpp"
        using namespace std;

        int main(){
            Matrixx mat{5, 6};

            mat.set(1, 2, 3);
            mat.set(0, 4, 6);

            cout << mat.get(1, 2) <<endl;
            cout << mat.get(4, 5) <<endl;

            cout << mat;
        }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

The `matrix.h` header file contains one **Virtual** base class `Matrix` and various classes inheriting it.

As `Matrix` is a **Virtual** class, you cannot initialize it directly, you have to take the object of the classes inheriting from it.

Following are the classes inheriting it.

#### _class Matrix_

This is the base class for all classes in Matrix.
This class is virtual so, cannot be instantiated

##### 1. Accessors (Getter Functions)

-   `virtual int at(int i, int j) const = 0` -> **Pure Virtual Function**. Returns the value at the **ith, jth** position of the matrix.
-   `virtual int** get() const = 0` -> **Pure Virtual Function**. Returns the whole 2D array.
-   `int getRows() const` -> Returns the number of rows of the matrix.
-   `int getCols() const` -> Returns the columns of the matrix.

##### 2. Mutators (Setter Functions)

-   `virtual void set(int i, int j, int num) = 0` -> **Pure Virtual Function**. Sets the value at the **ith, jth** position of the matrix.

#### _class Matrixx: public Matrix_

This class is for using normal 2D arrays.

##### 1. Constructors

-   `Matrixx(int m, int n)` -> Initializes an 2D array with the given dimensions **m X n**.
-   `Matrixx(int m, int n, int* matrix)` -> Initializes an 2D array with the given dimensions **m X n** and with the given 2D array. Eg:-

        int arr[][2] = {{1, 2}, {1, 2}};
        Matrixx M{2, 2, (int*)arr};

-   `Matrixx(const Matrixx &mat)` -> **_Copy Constructor_**. Initializes the Matrixx object by copying the 2D array from the given Matrixx object.

##### 2. Mutators (Setter Methods)

-   `void set(int i, int j, int num)` -> Sets the value at the specified **i** and **j** of the 2D array.

##### 3. Accessors (Getter Methods)

-   `int** get() const` -> Returns the pointer to the complete 2D array.
-   `int at(int i, int j) const` -> Returns the **value** at the specified **i, j**.

##### 4. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole 2D array. Eg. `cout << matrix;`, **output** :-

        1 2
        1 2

#### _class DiagonalMatrix: public Matrix_

This class if for using special type of Matrix - **_Diagonal Matrix_**.

Implements a Diagonal Matrix in a very space efficient manner by using 1D arrays for storing elements.

##### 1. Constructors

-   `DiagonalMatrix(int n, const int *diagonalElements)` -> Initializes a **n X n** matrix with the given diagonal elements. Eg :-

        int diagonalElements[5] = {3, 7, 4, 9, 6};
        DiagonalMatrix M{5, diagonalElements};

-   `DiagonalMatrix(const DiagonalMatrix& mat)` -> **_Copy Constructor_**. Initializes a diagonal matrix by copying from the given DiagonalMatrix object.

##### 2. Mutators (Setter Methods)

-   `void set(int i, int j, int num)` -> Sets the value at the specified **i** and **j** of the diagonal matrix.

##### 3. Accessors (Getter Methods)

-   `int** get() const` -> Returns the pointer to the complete matrix.
-   `int at(int i, int j) const` -> Returns the **value** at the specified **i, j**.

##### 4. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole matrix. Eg. `cout << matrix;`, **output** :-

        1 0 0 0
        0 2 0 0
        0 0 5 0
        0 0 0 3

#### _class LowerTriangularMatrix: public Matrix_

Implements **_Lower Triangular Matrix_** in a space efficient manner.

##### 1. Constructors

-   `LowerTriangularMatrix(int n, const int *rowMajorElements)` -> Initializes a **n X n** matrix with the given non-zero elements row by row. Eg :-

        int rowMajorElements[15] = {3, 7, 4, 9, 6, 5, 4, 7, 2, 1, 8, 4, 9, 3, 8};
        LowerTriangularMatrix M{5, diagonalElements};

-   `LowerTriangularMatrix(const LowerTriangularMatrix& mat)` -> **_Copy Constructor_**. Initializes a lower triangular matrix by copying from the given LowerTriangularMatrix object.

##### 2. Mutators (Setter Methods)

-   `void set(int i, int j, int num)` -> Sets the value at the specified **i** and **j** of the lower triangular matrix.

##### 3. Accessors (Getter Methods)

-   `int** get() const` -> Returns the pointer to the complete matrix.
-   `int* getRepresentation() const` -> Returns the 1D array of row major elements, in which the class is storing the non-zero elements of the matrix.
-   `int at(int i, int j) const` -> Returns the **value** at the specified **i, j**.

##### 4. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole matrix. Eg. `cout << matrix;`, **output** :-

        1 0 0 0
        3 2 0 0
        7 9 5 0
        6 3 2 3

#### _class UpperTriangularMatrix: public Matrix_

Implements **_Upper Triangular Matrix_** in a space efficient manner.

##### 1. Constructors

-   `UpperTriangularMatrix(int n, const int *rowMajorElements)` -> Initializes a **n X n** matrix with the given non-zero elements row by row. Eg :-

        int rowMajorElements[15] = {3, 7, 4, 9, 6, 5, 4, 7, 2, 1, 8, 4, 9, 3, 8};
        UpperTriangularMatrix M{5, diagonalElements};

-   `UpperTriangularMatrix(const UpperTriangularMatrix& mat)` -> **_Copy Constructor_**. Initializes an upper triangular matrix by copying from the given UpperTriangularMatrix object.

##### 2. Mutators (Setter Methods)

-   `void set(int i, int j, int num)` -> Sets the value at the specified **i** and **j** of the upper triangular matrix.

##### 3. Accessors (Getter Methods)

-   `int** get() const` -> Returns the pointer to the complete matrix.
-   `int* getRepresentation() const` -> Returns the 1D array of row major elements, in which the class is storing the non-zero elements of the matrix.
-   `int at(int i, int j) const` -> Returns the **value** at the specified **i, j**.

##### 4. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole matrix. Eg. `cout << matrix;`, **output** :-

        1 4 3 8
        0 2 2 9
        0 0 5 7
        0 0 0 3

#### _class SparseMatrix: public Matrix_

Implements a **_Sparse Matrix_** in a very space efficient manner.

Uses another class **_SparseElement_** for implementing the matrix.

##### 1. Constructors

-   `SparseMatrix(int m, int n)` -> Initializes a **m X n** matrix with all elements initialized from **0**. Eg :- `SparseMatrix S{8, 9};`

-   `SparseMatrix(const SparseMatrix& mat)` -> **_Copy Constructor_**. Initializes a sparse matrix by copying from the given SparseMatrix object.

##### 2. Mutators (Setter Methods)

-   `void set(int i, int j, int x)` -> Sets the value at the specified **i** and **j** of the matrix.

##### 3. Accessors (Getter Methods)

-   `int getSparseArrayLength() const` -> Returns the length of the array in which the class is storing all non zero elements of the matrix.
-   `int getSize() const` -> Returns the current maximum size of the **Sparse Array**. This size is automatically increased when needed.
-   `SparseElement *getSparseArray() const` -> Returns the **SparseArray** which is the array of **SparseElement** objects.
-   `int getSparseIndex(int i, int j)` -> Returns the index on which the given element with **i, j** position is stored in the **SparseArray**. If it is not found **-1** is returned;
-   `int** get() const` -> Returns the pointer to the complete matrix.
-   `int at(int i, int j) const` -> Returns the **value** at the specified **i, j**.

##### 4. Facilitators

-   `SparseMatrix* add(const SparseMatrix& s) const` -> Adds the given SparseMatrix with the current SparseMatrix and returns a pointer to the new SparseMatrix object.

##### 5. Operator Overloads

-   Addition Operator(`+`) -> For adding the two SparseMatrix. Eg. `cout << S1 + S2;`
-   Insertion Operator(`<<`) -> For printing the whole matrix. Eg. `cout << matrix;`, **output** :-

        1 0 0 0
        0 2 0 9
        0 0 0 0
        0 0 5 0

## LinkedList

-   Implements the linked list.
-   Built on template classes, so can be used for any data type

### How to use

1.  Place the files `linked_list.h` and `linked_list.cpp` inside the root folder of your project
2.  Example code to use `LinkedList`:

        // main.cpp
        #include<iostream>
        #include"linked_list.h"
        #include"linked_list.cpp"
        using namespace std;

        int main(){
            int arr[]{1, 2, 3, 4, 5};
            LinkedList<int> LL{5, arr};

            LL.append(1);
            LL.prepend(5);
            LL.insert(3, 8);

            cout << LL.size() <<endl;

            cout << LL[2];
            LL[2] = 10;

            LL.display();
        }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

-   Implemention of Linked List in an efficient manner

#### 1. Constructors

-   `LinkedList()` -> Initializes an empty linked list.
-   `LinkedList(int n, const T arr[])` -> Initializes an linked list from the given array.

#### 2. Accessors (Getter Methods)

-   `int size() const` -> Returns the length of the linked list.
-   `T at(int index) const` -> Returns the element at the specified index.

#### 3. Mutators (Setter Methods)

-   `void insert(int index, T data)` -> Inserts the element at the specified index in the linked list.
-   `T remove(int index)` -> Removes the element at the specified index.
-   `void prepend(T data)` -> Inserts the given element at the begin of the linked list.
-   `void append(T data)` -> Appneds the given element at the end of the linked list.
-   `T pop_front()` -> Pops and returns the element from the beginning of the linked list.
-   `T pop_back` -> Pops and returns the element from the end of the linked list.

#### 4. Facilitators

-   `void display() const` -> Prints space separated all the members of the linked list.
-   `void reverse()` -> Reverses the Linked List.
-   `void concat(LinkedList& ll)` -> Concatenates the given linked list at the end of the linked list.

#### 5. Enquiry Functions

-   `bool isEmpty() const` -> Returns true if the linked list is empty.

#### 5. Operator Overloads

-   Subscript Operator(`[]`) -> Can be used to **access** and **assign** the value.
-   Insertion Operator(`<<`) -> For printing the whole linked list. Eg. `cout << ll;` **output** - `1 2 3 4 5`

## Stack

-   Implements the dynamic stack.
-   Built on template classes, so can be used for any data type

### How to use

1.  Place the files `stack.h` and `stack.cpp` inside the root folder of your project
2.  Example code to use `Stack`:

        // main.cpp
        #include<iostream>
        #include"stack.h"
        #include"stack.cpp"
        using namespace std;

        int main(){
            Stack<int> st{5};

            st.push(1);
            st.push(5);
            st.push(8);

            cout << st.getSize() <<endl;
            cout << st.getCapacity() <<endl;

            st.pop();
            cout << st;

        }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

The Stack class maintains an array, with its 3 properties:- **size** and **capacity** and the **top pointer**.

**size** -> It is the size of the stack, or the number of elements currently filled in the stack.

**capacity** -> It is the maximum number of elements it can hold presently. It is increased automatically as the user fills the stack. The default capacity is 10.

**top pointer** -> It is the pointer pointing to the top element of the stack.

#### 1. Constructors

-   `Stack()` -> Initializes a stack.
-   `Stack(int capacity)` -> Initializes a stack with the given **capacity**.
-   `Stack(int size, T arr[])` -> Initializes a stack with the given **size** and fills it with the given **array**.
-   `Stack(int capacity, const LinkedList<T>& ll)` -> Initializes the stack with the given **capacity** and fill the stack from the elements given in the LinkedList.
-   `Stack(const Stack<T>& stack)` -> **_Copy Constructor_**. Initializes the Stack object by copying the stack from the given Stack object.

#### 2. Mutators (Setter Methods)

-   `T pop() const` -> Removes the topmost element of the stack and returns the value.
-   `void push(T ele)` -> Pushes the given element at the top of the stack.

#### 3. Accessors (Getter Methods)

-   `T peek() const` -> Returns the value of the topmost element of the stack.
-   `int getSize() const` -> Returns the current size of the stack.
-   `int getCapacity() const` -> Returns the current maximum capacity of the stack.

#### 4. Enquiry Functions

-   `bool isEmpty() const` -> Returns wether the stack is empty or not.

#### 5. Facilitators

-   `void display() const` -> Displays all the elements of the stack from top to bottom.

#### 5. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole stack from top to bottom.

## Queue

-   Implements the **QUEUE** Data Structure.
-   Built on template classes, so can be used for any data type

### How to use

1.  Place the files `queue.h` and `queue.cpp` inside the root folder of your project
2.  Example code to use `Queue`:

        // main.cpp
        #include<iostream>
        #include"queue.h"
        #include"queue.cpp"
        using namespace std;

        int main(){
            int arr[]{1, 2, 3, 4, 5}
            Queue<int> q{5, arr};

            cout << "Front: " << q.getFront() << ", Rear: " << q.getRear() << ", Size: " << q.size() << endl << endl;
            q.display();
            cout << endl;

            q.enqueue(8);
            cout << q.dequeue() << endl;

            cout << q;
        }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

The Queue class maintains a Queue, with its 2 properties:- **front**, **rear** and **length**.

**front** -> It is the pointer to the **front** node of the Queue.

**rear** -> It is the pointer to the **last** node of the Queue.

**length** -> It is the length of the Queue or the number of elements present inside the Queue.

#### 1. Constructors

-   `Queue()` -> Initializes a Queue with **front = NULL**, **rear = NULL** and **length = 0**.
-   `Queue(int length, T arr[])` -> Initializes a Queue with the given **length** and fills it with the given **array**.

#### 2. Mutators (Setter Methods)

-   `void enqueue(T data)` -> Pushes the given element inside the Queue.
-   `T dequeue()` -> Pop out and return the first element of the Queue according to the **FIFO (First In First Out)** rule.

#### 3. Accessors (Getter Methods)

-   `int size() const` -> Returns the **length** of the Queue.
-   `int getFront() const` -> Returns the value of the **Front** Node.
-   `T getRear() const` -> Returns the value of the **Rear** Node.

#### 4. Facilitators

-   `void display() const` -> Prints space separated all the members of the Queue.

#### 5. Enquiry Functions

-   `bool isEmpty() const` -> Returns `true` if the Queue is **Empty**.

#### 6. Operator Overloads

-   Insertion Operator(`<<`) -> For printing the whole Queue. Eg. `cout << q;` **output** - `1 2 3 4 5`

## Binary Tree

-   Implements the **Binary Tree** Data Structure.
-   Built on template classes, so can be used for any data type

### How to use

1.  Place the files `queue.h` and `queue.cpp` inside the root folder of your project
2.  Example code to use `Queue`:

        // main.cpp
        #include<iostream>
        #include"bin_tree.h"
        #include"bin_tree.cpp"
        using namespace std;

        int main(){
            bin_tree_node::Node<int> n6{8};
            bin_tree_node::Node<int> n7{9};
            bin_tree_node::Node<int> n3{3, &n6, &n7};

            bin_tree_node::Node<int> n4{2};
            bin_tree_node::Node<int> n5{1};
            bin_tree_node::Node<int> n2{4, &n4, &n5};

            bin_tree_node::Node<int> n1{5, &n1, &n2};

            BinTree<int> tree{&n1};

            tree.displayAsPreorder();
            cout << endl;
            tree.displayAsInorder();
            cout << endl;
            tree.displayAsPostorder();
            cout << endl;
            tree.displayAsLevelorder();
        }

3.  To compile and run the code, write in terminal:
    > g++ main.cpp -o main && main.exe

### Documentation

The **Binary Tree** implements a binary tree with the help of 1 Class and 1 Struct:- `class BinTree` and `struct node_bin_tree::Node`.

The single nodes of **BinTree** class are based on the `struct bin_tree_node::Node<T>` .

#### `struct bin_tree_node::Node<T>`

##### 1. Properties

-   `T data` -> **data** of the node
-   `struct Node<T>* lchild` -> Pointer to the **left child**.
-   `struct Node<T>* rchild` -> Pointer to the **right child**.

##### 2. Constructor

-   `Node(T data=static_cast<T>(0), stuct Node<T> *lchild=NULL, stuct Node<T>* rchild=NULL)` -> Initialises a new node with given data, left child, and right child.

#### `class BinTree`

##### 1. Constructors

-   `BinTree()` -> Initializes an empty Binary Tree.
-   `BinTree(T root_val)` -> Initializes a Binary Tree with the given data value of root node.
-   `BinTree(bin_tree_node::Node<T>* root)` -> Initializes a Binary Tree with the given root node.
-   `BinTree(BinTree<T>& bin_tree)` -> Clones a previously present binary tree.

##### 2. Mutators (Setter Methods)

-   `createTreeFromUserInput()` -> Destroys the current Binary Tree and creates new binary tree by taking input from the user. **NOTE: -** You can give -1 as input whereever you don't want a child Node.
-   `destroyCurrentBinaryTree()` -> Destroys current Binary Tree and set root node to NULL.
-   `destroyCurrentBinaryTree(bin_tree_node::Node<T>* root)` -> Destroys the binary tree starting from the given node.

##### 3. Accessors (Getter Methods)

-   `T* preorder() const` -> Returns an array filled with the elements of binary tree in **Preorder** sequence.
-   `T* preorder(bin_tree_node::Node<T>* root) const` -> Returns an array filled with the elements of binary tree in **Preorder** sequence starting from the given node.
-   `T* inorder() const` -> Returns an array filled with the elements of binary tree in **Inorder** sequence.
-   `T* inorder(bin_tree_node::Node<T>* root) const` -> Returns an array filled with the elements of binary tree in **Inorder** sequence starting from the given node.
-   `T* postorder() const` -> Returns an array filled with the elements of binary tree in **Postorder** sequence.
-   `T* postorder(bin_tree_node::Node<T>* root) const` -> Returns an array filled with the elements of binary tree in **Postorder** sequence starting from the given node.
-   `T* levelorder() const` -> Returns an array filled with the elements of binary tree in **Levelorder** sequence.
-   `T* levelorder(bin_tree_node::Node<T>* root) const` -> Returns an array filled with the elements of binary tree in **Levelorder** sequence starting from the given node.
-   `bin_tree_node::Node<T>* getRootNode() const` -> Returns the root node.
-   `int height() const` -> Returns the height of the binary tree.
-   `int height(bin_tree_node::Node<T>* root) const` -> Returns the height of the binary tree starting from the given node.
-   `int nodesCount() const` -> Returns the number of nodes present in the tree.
-   `int nodesCount(bin_tree_node::Node<T>* root) const` -> Returns the number of nodes present in the tree starting from the given node.

##### 4. Facilitators

-   `void displayAsPreorder() const` -> Displays the tree in the **Preorder** sequence.
-   `void displayAsPreorder(bin_tree_node::Node<T>* root) const` -> Displays the tree in the **Preorder** sequence starting from the given node.
-   `void displayAsPostorder() const` -> Displays the tree in the **Postorder** sequence.
-   `void displayAsPostorder(bin_tree_node::Node<T>* root) const` -> Displays the tree in the **Postorder** sequence starting from the given node.
-   `void displayAsInorder() const` -> Displays the tree in the **Inorder** sequence.
-   `void displayAsPreorder(bin_tree_node::Node<T>* root) const` -> Displays the tree in the **Inorder** sequence starting from the given node.
-   `void displayAsLevelorder() const` -> Displays the tree in the **Levelorder** sequence.
-   `void displayAsLevelorder(bin_tree_node::Node<T>* root) const` -> Displays the tree in the **Levelorder** sequence starting from the given node.

##### 5. Enquiry Functions

-   `bool isEmpty() const` -> Returns `true` if the binary tree is **Empty** or root is **NULL**.

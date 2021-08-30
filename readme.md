# Array - A Library for using resizable arrays

## How to use

1.  Place the files `array.h` and `array.cpp` inside the root folder of your project
2.  Example code to use the library:
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

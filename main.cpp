#include<iostream>
#include "array.h"
#include "array.cpp"
using namespace std;

int main()
{
    int a[]{1, 2, 3, 4, 5};
    Array<int> a1{5, a};
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;


    a1.insert(4, 10);
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;


    cout << a1.append(8) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;


    cout << a1.del(2) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.remove(2) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.remove(50) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.get(4) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.set(4, 40);
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.pop() << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.search(5) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.search(5, false) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.bin_search(5) << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.max() << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << a1.min() << endl;
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.reverse();
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.l_rotate();
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.r_rotate();
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.l_shift();
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    a1.r_shift();
    cout << a1.getLength() << ", " << a1.getSize() << endl;
    a1.display();
    cout << endl;

    cout << "Element at 3rd index -> " << a1[3] << endl;
    a1.display();
    a1[3] = 50;
    cout << "Updated element at 3rd index -> " << a1[3] << endl;
    a1.display();
    cout << endl;

    cout << a1 << endl;

    Array<int> a2{a1};
    cout << a2;

    cin.get();
    return 0;
}

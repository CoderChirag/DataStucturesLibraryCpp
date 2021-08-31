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

    cin.get();
    return 0;
}

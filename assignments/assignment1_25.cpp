#include<iostream>
#include "../linked_list.h"
#include "../linked_list.cpp"

using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList<int> ll{5, arr};
    ll.reverse();
    cout << ll;
    return 0;
}
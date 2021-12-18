#include<iostream>
#include "../linked_list.h"
#include "../linked_list.cpp"

using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList<int> ll{5, arr};
    int count = 0;
    for (int i = 0; i < ll.size(); i++){
        count++;
    }
    cout << count;
    return 0;
}
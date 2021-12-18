#include<iostream>
#include"linked_list.h"
#include"linked_list.cpp"
using namespace std;

void bubble_sort(LinkedList<int> &ll);
void remove_duplicates(LinkedList<int> &ll);
int sum(LinkedList<int> &ll);
void delete_odd(LinkedList<int> &ll);

int main()
{
    int arr[]{6, 2, 8, 1, 2, 1, 2, 2};
    LinkedList<int> ll{8, arr};
    cout << ll << endl;
    bubble_sort(ll);
    cout << ll << endl;
    remove_duplicates(ll);
    cout << ll << endl;
    cout << "sum: " << sum(ll) << endl << endl;
    delete_odd(ll);
    cout << ll << endl;
    return 0;
}

void bubble_sort(LinkedList<int>& ll){
    if(ll.size() == 0){
        return;
    }
    for (int i = 0; i < ll.size(); i++){
        for (int j = i+1; j < ll.size(); j++){
            if(ll[j] < ll[i]){
                int temp = ll[i];
                ll[i] = ll[j];
                ll[j] = temp;
            }
        }
    }
}

void remove_duplicates(LinkedList<int> &ll){
    if(ll.size() == 0){
        return;
    }
    int i = 0;
    while(i < ll.size()-1){
        if(ll[i+1] == ll[i]){
            ll.remove(i + 1);
        }else{
            i++;
        }
    }
}

int sum(LinkedList<int> &ll){
    int sum = 0;
    for (int i = 0; i < ll.size(); i++){
        sum += ll[i];
    }
    return sum;
}

void delete_odd(LinkedList<int> &ll){
    int i = 0;
    while(i < ll.size()){
        if(ll[i]%2 != 0){
            ll.remove(i);
        }else{
            i++;
        }
    }
}
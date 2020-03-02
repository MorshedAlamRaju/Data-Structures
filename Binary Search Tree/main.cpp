#include<iostream>
#include "bst.h"
using namespace std;

int main(){
    int arr[] = {5, 3, 2, 7, 10};

    BST tree(arr, 5);
    tree.insert_key(15);
    tree.insert_key(154);
    tree.insert_key(5);
    tree.insert_key(1);
    tree.insert_key(-15);
    tree.insert_key(155);
    cout << tree.get_size() << endl;
    cout << tree.get_min() << endl;
    cout << tree.get_max() << endl;

    return 0;
}

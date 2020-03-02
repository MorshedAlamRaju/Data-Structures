#include "node.h"
#include "bst.h"

#include<cstdlib>
BST::BST(){
    root = NULL;
    tree_size = 0;
}

BST::BST(int arr[]){
    int *p = arr;
    tree_size = 0;
    while(p){
//        insert_key(*p);
        ++p;
        tree_size++;
    }
}

Node* BST::get_root(){
    return root;
}


int BST::get_size(){
    return tree_size;
}

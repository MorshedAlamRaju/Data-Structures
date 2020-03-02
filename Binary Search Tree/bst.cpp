#include "node.h"
#include "bst.h"

#include<cstdlib>

BST::BST(){
    root = new Node();
    tree_size = 0;
}

BST::BST(int arr[], int n){
    root = new Node();
    tree_size = 0;

    int idx  = 0;
    while(idx < n){
        insert_key(arr[idx]);
        ++idx;
    }
}

Node* BST::get_root(){
    return root;
}

int BST::get_size(){
    return tree_size;
}

void BST::insert_key(int key){
    Node *cur = root;
    Node *temp = NULL;
    tree_size++;

    while(cur != NULL){
        temp = cur;
        int cur_key = cur->get_key();
        if(cur_key < key)
            cur = cur->get_right();
        else cur = cur->get_left();
    }

    Node *add = new Node(key);
    add->set_parent(temp);

    if(temp == NULL)
        root = add;
    else if(add->get_key() < temp->get_key())
        temp->set_left(add);
    else
        temp->set_right(add);
}

int BST::get_min(){
    Node *n = root;
    while(n->get_left() != NULL)
        n = n->get_left();
    return n->get_key();
}

int BST::get_max(){
    Node *n = root;
    while(n->get_right() != NULL)
        n = n->get_right();
    return n->get_key();
}

int BST::get_max(Node *n){
    while(n->get_right() != NULL)
        n = n->get_right();
    return n->get_key();
}

int BST::get_min(Node *n){
    while(n->get_left() != NULL)
        n = n->get_left();
    return n->get_key();
}


bool BST::search_key(int key){
    Node *n = root;
    while(n != NULL){
        if(n->get_key() == key)
            return true;
        else if(n->get_key() < key)
            n = n->get_right();
        else
            n = n->get_left();
    }
    return false;
}

Node* BST::get_node(int key){
    Node *n = root;
    while(n != NULL){
        if(n->get_key() == key)
            return n;
        else if(n->get_key() < key)
            n = n->get_right();
        else
            n = n->get_left();
    }
    return n;
}

int BST::get_successor(int key){
    Node *n = get_node(key);
    return get_min(n->get_right());
}

int BST::get_predecessor(int key){
    Node *n = get_node(key);
    return get_max(n->get_left());
}

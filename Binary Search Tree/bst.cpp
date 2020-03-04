#include "node.h"
#include "bst.h"

#include<cstdlib>


template<typename T> BST<T>::BST(){
    root = new Node<T>();
    tree_size = 0;
}

template<typename T> BST<T>::BST(T arr[], int n){
    root = new Node<T>();
    tree_size = 0;

    int idx  = 0;
    while(idx < n){
        insert_key(arr[idx]);
        ++idx;
    }
}



template<typename T> Node<T>* BST<T>::get_root(){ return root; }


template<typename T> int BST<T>::get_size(){ return tree_size; }


template<typename T> void BST<T>::insert_key(T key){
    Node<T> *cur = root;
    Node<T> *temp = NULL;
    tree_size++;

    while(cur != NULL){
        temp = cur;
        T cur_key = cur->get_key();
        if(cur_key < key)
            cur = cur->get_right();
        else cur = cur->get_left();
    }

    Node<T> *add = new Node<T>(key);
    add->set_parent(temp);

    if(temp == NULL)
        root = add;
    else if(add->get_key() < temp->get_key())
        temp->set_left(add);
    else
        temp->set_right(add);
}


template<typename T> T BST<T>::get_min(){
    Node<T> *n = root;
    while(n->get_left() != NULL)
        n = n->get_left();
    return n->get_key();
}


template<typename T> T BST<T>::get_max(){
    Node<T> *n = root;
    while(n->get_right() != NULL)
        n = n->get_right();
    return n->get_key();
}


template<typename T> T BST<T>::get_max(Node<T> *n){
    while(n->get_right() != NULL)
        n = n->get_right();
    return n->get_key();
}


template<typename T> T BST<T>::get_min(Node<T> *n){
    while(n->get_left() != NULL)
        n = n->get_left();
    return n->get_key();
}



template<typename T> bool BST<T>::search_key(T key){
    Node<T> *n = root;
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


template<typename T> Node<T>* BST<T>::get_node(T key){
    Node<T> *n = root;
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


template<typename T> T BST<T>::get_successor(T key){
    Node<T> *n = get_node(key);
    return get_min(n->get_right());
}


template<typename T> T BST<T>::get_predecessor(T key){
    Node<T> *n = get_node(key);
    return get_max(n->get_left());
}

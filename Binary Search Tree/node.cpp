#include "node.h"
#include <cstdlib>

template<typename T> Node<T>::Node(){
    parent = NULL;
    left = NULL;
    right = NULL;
}

template<typename T> Node<T>::Node(T key){
    this->key = key;
    parent = NULL;
    left = NULL;
    right = NULL;
}

template<typename T> void Node<T>::set_parent(Node *parent){ this->parent = parent; }

template<typename T> void Node<T>::set_left(Node *left){ this->left = left; }

template<typename T> void Node<T>::set_right(Node *right){ this->right = right; }

template<typename T> void Node<T>::set_key(T key){ this->key = key; }

template<typename T> T Node<T>::get_key(){ return key; }

template<typename T> Node<T>* Node<T>::get_parent(){ return parent; }

template<typename T> Node<T>* Node<T>::get_left(){ return left; }

template<typename T> Node<T>* Node<T>::get_right(){ return right; }

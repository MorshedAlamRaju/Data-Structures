#ifndef __BST_H_
#define __BST_H_

#include "node.h"

template<typename T> class BST{
    Node<T> *root;
    int tree_size;

    public:
        BST();
        BST(T arr[], int n);

        Node<T>* get_root();
        Node<T>* get_node(T key);
        int get_size();

        T get_max(Node<T> *n);
        T get_min(Node<T> *n);
        T get_min();
        T get_max();

        T get_successor(T key);
        T get_predecessor(T key);
        bool search_key(T key);

        void insert_key(T key);
        void delete_key(T key);

        void inorder_tree_walk();
        void preorder_tree_walk();
        void postorder_tree_walk();

    private:
        void transplant();

};

#endif // __BST_H

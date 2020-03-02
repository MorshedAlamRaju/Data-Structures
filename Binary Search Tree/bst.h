#ifndef __BST_H_
#define __BST_H_

#include "node.h"

class BST{
    Node *root;
    int tree_size;

    public:
        BST();
        BST(int arr[], int n);

        Node* get_root();
        int get_size();
        int get_min();
        int get_max();
        int get_successor(int key);
        int get_predecessor(int key);
        bool search_key(int key);

        void insert_key(int key);
        void delete_key(int key);

        void inorder_tree_walk();
        void preorder_tree_walk();
        void postorder_tree_walk();

    private:
        Node* get_node(int key);
        void transplant();
        int get_max(Node *n);
        int get_min(Node *n);

};

#endif // __BST_H

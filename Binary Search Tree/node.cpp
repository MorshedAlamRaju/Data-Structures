#include "node.h"
#include <cstdlib>

Node::Node(){
    key = -1;
    parent = NULL;
    left = NULL;
    right = NULL;
}

Node::Node(int key){
    this->key = key;
    parent = NULL;
    left = NULL;
    right = NULL;
}

void Node::set_parent(Node *parent){
    this->parent = parent;
}

void Node::set_left(Node *left){
    this->left = left;
}

void Node::set_right(Node *right){
    this->right = right;
}

void Node::set_key(int key){
    this->key = key;
}

int Node::get_key(){
    return key;
}

Node* Node::get_parent(){
    return parent;
}

Node* Node::get_left(){
    return left;
}

Node* Node::get_right(){
    return right;
}

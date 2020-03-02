#ifndef __NODE_H_
#define __NODE_H_

class Node{
    Node *parent;
    Node *left;
    Node *right;
    int key;

    public:
        /// Constructor and Destructor
        Node();
        Node(int key);
        ~Node();

        /// Getter
        int get_key();
        Node* get_parent();
        Node* get_left();
        Node* get_right();

        /// Setter
        void set_key(int key);
        void set_left(Node *left);
        void set_right(Node *right);
        void set_parent(Node *parent);
};

#endif // __NODE_H_

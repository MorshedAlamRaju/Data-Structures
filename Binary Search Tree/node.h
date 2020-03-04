#ifndef __NODE_H_
#define __NODE_H_

template<typename T>
class Node{
    Node *parent;
    Node *left;
    Node *right;
    T key;

    public:
        /// Constructor and Destructor
        Node();
        Node(T key);
        ~Node();

        /// Getter
        T get_key();
        Node* get_parent();
        Node* get_left();
        Node* get_right();

        /// Setter
        void set_key(T key);
        void set_left(Node *left);
        void set_right(Node *right);
        void set_parent(Node *parent);
};

#endif // __NODE_H_

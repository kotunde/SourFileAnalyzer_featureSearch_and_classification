//
// Created by attila on 28.11.2018.
//

#ifndef BST_BST_H
#define BST_BST_H

/*
* Binary search tree
*/
class BST {
public:
// destructor
    virtual~BST(){}
// inserts "val" into the tree
    void insert(int val);
// returns true if and only if "val" exists in the tree.
    bool find(int val) const;
// prints the tree elements in the in-order traversal order
    void print_inorder() const;
// prints the tree elements in the pre-order traversal order
    void print_preorder() const;
// prints the tree elements in the post-order traversal order
    void print_postorder() const;
};


#endif //BST_BST_H

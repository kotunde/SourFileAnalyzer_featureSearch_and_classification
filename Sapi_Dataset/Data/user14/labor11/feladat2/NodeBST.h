//
// Created by attila on 28.11.2018.
//

#ifndef BST_NODEBST_H
#define BST_NODEBST_H

#include "BST.h"
class NodeBST: public BST
{
    struct Node
    {
        int val;
        Node * left, *right;
        Node( int val = 0, Node * left = nullptr, Node * right = nullptr):val(val),
                                                                          left(left), right(right){}
    };

    Node * root;

// Helper functions for travelsals
    void inorder( Node * node) const;
    void preorder( Node * node) const;
    void postorder( Node * node) const;
//Helper function for destructor
    void deleteSubTree(Node * node);
public:
    NodeBST();
    virtual ~NodeBST() override;
    void insert(int val);
    bool find(int val) const;
    void print_inorder() const;
    void print_preorder() const;
    void print_postorder() const;
};


#endif //BST_NODEBST_H

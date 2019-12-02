//
// Created by attila on 28.11.2018.
//

#include <iostream>
#include "NodeBST.h"



using namespace std;

void NodeBST::inorder(NodeBST::Node *node) const
{
//    if (node==nullptr)
//        return;
//    inorder(node->left);
//    cout << node->val << " ";
//    inorder(node->right);
    ///optimalisabb megoldas
    if (node->left!= nullptr)
    {
        inorder(node->left);
    }
    cout << node->val << " ";
    if (node->right!= nullptr)
    {
        inorder(node->right);
    }
    return;
}

void NodeBST::preorder(NodeBST::Node *node) const
{
//    if (node==nullptr)
//        return;
//    cout << node->val << " ";
//    inorder(node->left);
//    inorder(node->right);
    cout << node->val << " ";
    if (node->left!= nullptr)
    {
        inorder(node->left);
    }
    if (node->right!= nullptr)
    {
        inorder(node->right);
    }
    return;
}

void NodeBST::postorder(NodeBST::Node *node) const
{
//    if (node==nullptr)
//        return;
//    inorder(node->left);
//    inorder(node->right);
//    cout << node->val << " ";
    if (node->left!= nullptr)
    {
        inorder(node->left);
    }
    if (node->right!= nullptr)
    {
        inorder(node->right);
    }
    cout << node->val << " ";
    return;
}

void NodeBST::deleteSubTree(NodeBST::Node *node)
{
    if (node->left!= nullptr)
    {
        deleteSubTree(node->left);
    }
    if (node->right!= nullptr)
    {
        deleteSubTree(node->right);
    }
    delete node;

}

NodeBST::NodeBST()
{

}

NodeBST::~NodeBST()
{
    delete root;
}

void NodeBST::insert(int val)
{
    if (root= nullptr)
    {
        root->val=val;
    }
    else
    {
        Node* act=root;

        if (val < act->val)
        {
            while (act->val>val)
            {
                act=act->left;
            }
            if (act==nullptr)
            {
                act=new Node();

            }
            else
            {

            }

        }
        else if (val > act->val)
        {
            if (act->right= nullptr)
            {
                act->right=new Node;
                act->right->val=val;
            }
            else
            {

            }
        }
    }

}

bool NodeBST::find(int val) const
{
    if (root->val==val)
    {

    }
}

void NodeBST::print_inorder() const
{
    inorder(root);
}

void NodeBST::print_preorder() const
{
    preorder(root);
}

void NodeBST::print_postorder() const
{
    postorder(root);
}

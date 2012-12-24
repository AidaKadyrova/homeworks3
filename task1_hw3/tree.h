#pragma once
#include <iostream>
#include <iterator>
#include <QStack>
#include "node.h"
#include "treeIterator.h"

class Tree
{
public:

    /**
     * constructor for Tree
     */
    Tree():root(NULL){}
    /**
     * check if tree is empty
     * @return true, if tree is empty, false, if tree isn't empty
     */
    bool isEmpty()
    {
        return (root == NULL);
    }
    /**
    * add new element to the tree
    * @param val value to add
    */
    void addElement(int val);
    /**
     * check if the element is in tree
     * @param value value of element
     * @return true, if element is found, false, if element isn't found
     */
    bool findElement(int val);
    /**
     * root of the tree
     * @return root of the tree
     */
    Node* getRoot()
    {
        return root;
    }
    class TreeIterator
    {
    public:
        TreeIterator(Tree* tree);
        int operator++();


    private:
        Node* current;
        QStack<Node*> stack;

    };


private:
    Node* root;
};

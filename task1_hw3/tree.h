#pragma once
#include <iostream>
#include <iterator>
#include <QList>
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
    void deleteElement(int val);

    Node* getRoot()
    {
        return root;
    }

    class TreeIterator
    {
    public:
        TreeIterator(): current(NULL), next(NULL), tree(NULL), wasDeleted(false) {}
        TreeIterator(Tree* t, Node *p): current(p), tree(t), wasDeleted(false)
        {
            next= getNext(p);

        }
        TreeIterator operator++();
        bool operator!=(const TreeIterator &it)
        {
            return current != it.current;
        }
        int operator*()
        {
            if (current != NULL)
                return current->getValue();
            else
                return -1;
        }
        void deleteCurrent();

    private:
        Node* getNext(Node *current);
        Node* current;
        Node* next;
        Tree* tree;
        bool wasDeleted;

    };

    TreeIterator begin();
    TreeIterator end();

private:
    Node* root;
};

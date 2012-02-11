
#include <iostream>
#include <iterator>
#include "tree.h"

void Tree::addElement(int val)
{
    if (isEmpty())
    {
        root = new Node(val);
    }
    else
    {
        root->addElement(val);

    }
    if(!treeIteratorList.isEmpty())
        updateIteratorList();
}

bool Tree::findElement(int val)
{
    if (!isEmpty())
    {
        return root->findElement(val);
    }
    else
    {
        return false;
    }
}

void Tree::updateIteratorList()
{
    int length = treeIteratorList.length();
    for (int i = 0; i < length; i++)
    {
        TreeIterator* t =  treeIteratorList.at(i);
        t->updateIterator(root);
    }
}




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

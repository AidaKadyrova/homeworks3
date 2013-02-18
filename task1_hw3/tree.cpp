
#include <iostream>
#include <iterator>
#include "tree.h"

void Tree::addElement(int val)
{
    if (isEmpty())
        root = new Node(val);
    else
        root->addElement(val);

}

bool Tree::findElement(int val)
{
    if (!isEmpty())
        return root->findElement(val);
    else
        return false;
}


void Tree::deleteElement(int val)
{
    if (isEmpty())
        return;
    Node* tmp = root;
    root->deleteNode(tmp, val);
}


Tree::TreeIterator Tree::begin()
{
    Node *current = root;
    while (current->getLeft() != NULL)
        current = current->getLeft();

    return TreeIterator(this, current);
}

Tree::TreeIterator Tree::end()
{
    return TreeIterator(this, NULL);
}


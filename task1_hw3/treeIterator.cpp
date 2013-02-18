#include "tree.h"
#include <iostream>

Tree::TreeIterator Tree::TreeIterator::operator++()
{
    if (current != NULL)
    {
        current = next;
        next = getNext(current);
        wasDeleted = false;
    }
    return *this;
}

Node* Tree::TreeIterator::getNext(Node *current)
{
    if (current == NULL)
    {
        return NULL;
    }
    if (current->getRight() != NULL)
    {
        current = current->getRight();
        while (current->getLeft() != NULL)
        {
            current = current->getLeft();
        }
    } else
    {
        if (current->getParent() == NULL)
        {
            current = NULL;
            return NULL;
        }
        while (current->getParent()->getRight() == current)
        {
            current = current->getParent();
            if (current->getParent() == NULL)
            {
                current = NULL;
                return NULL;
            }
        }
        current = current->getParent();
    }
    return current;
}

void Tree::TreeIterator::deleteCurrent()
{
    if (!wasDeleted)
    {
        next = getNext(current);
        tree->deleteElement(current->getValue());
        wasDeleted = true;
    }
}


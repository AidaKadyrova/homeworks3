#include "tree.h"
#include <iostream>

Tree::TreeIterator::TreeIterator(Tree *tree)
{
       current = tree->getRoot();
       stack.push(current);

}

int Tree::TreeIterator::operator++()
{
    if(current != NULL){

    current = stack.pop();
    int value = current->getValue();
    if (current->getRight() != NULL)
        stack.push(current->getRight());
    if (current->getLeft() != NULL)
        stack.push(current->getLeft());
    if (stack.empty())
        current = NULL;
    return value;
}
    else return 0;

}




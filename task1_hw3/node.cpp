#include "node.h"
#include <iostream>


void Node::addElement(int val)
{
    if(val < this->getValue())
    {
        if (this->getLeft() == NULL)
        {
            Node* temp = new Node(val);
            this->setLeft(temp);
        }
        else
        {
            this->getLeft()->addElement(val);
        }
    }
    else
    {
        if (this->getRight() == NULL)
        {
            Node* temp = new Node(val);
            this->setRight(temp);
        }
        else
        {
            this->getRight()->addElement(val);
        }
    }
}

bool Node::findElement(int val)
{
    if(this != NULL)
    {
        if (val == this->getValue())
        {
            return true;
        }
        else if((val < this->getValue()) && (this->getLeft() != NULL))
        {
            return this->getLeft()->findElement(val);
        }
        else if((val > this->getValue()) && (this->getRight() != NULL))
        {
            return this->getRight()->findElement(val);
        }
        else
            return false;

    }
    else
        return false;

}

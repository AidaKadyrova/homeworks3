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
            temp->parent = this;
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
            temp->parent = this;
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

void Node::deleteNode(Node *&n, int val)
{
    if (n == NULL)
        return;
    if (n->getValue() < val)
    {
        deleteNode(n->right, val);
        if (n->right != NULL)
            n->right->parent = n;
    }
    else
        if (n->getValue() > val)
        {
            deleteNode(n->left, val);
            if (n->left != NULL)
                n->left->parent = n;
        }
    else
        if ((n->getLeft() == NULL) && (n->getRight() == NULL))
        {
            delete(n);
            n = NULL;
        }
    else
        if ((n->getLeft() == NULL) && (n->getRight() != NULL))
        {
            Node* tmp = n;
            n = n->right;
            delete(tmp);
        }
    else
        if ((n->getLeft() != NULL) && (n->getRight() == NULL))
        {
            Node* tmp = n;
            n = n->left;
            delete(tmp);
        }
    else
        {
            Node* tmp = n;
            n = findLeftest(n->right);
            n->left = tmp->left;
            if (n->left != NULL)
                n->left->parent = n;
            n->right = tmp->right;
            if (n->right != NULL)
                n->right->parent = n;
            delete(tmp);
        }
}

Node* Node::findLeftest(Node *t)
{
    Node *parent = NULL;
    while (t->left != NULL)
    {
        parent = t;
        t = t->left;
    }
    if (parent != NULL)
    {
        parent->left = NULL;
    }
    return t;
}

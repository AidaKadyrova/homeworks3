#pragma once
#include <iostream>
class Node
{
public:
    /**
     * conctructor for Node
     */
    Node(int val): value(val), left(NULL), right(NULL){}
    /**
     * get left son
     * @return left son of the element
     */
    Node* getLeft(){ return left; }

    /**
     * get right son
     * @return right son of the element
     */
    Node* getRight(){ return right; }
    /**
     * get value
     * @return value of the element
     */
    int getValue(){ return value; }
    /**
     * set left son
     * @param left element which will be left son of the current
     */
    void setRight(Node* mRight){ this->right = mRight; }
    /**
     * set right son
     * @param right element which will be right son of the current
     */
    void setLeft(Node* mLeft){ this->left = mLeft; }
    /**
     * add new element to the tree
     * @param value value to add
     */
    void addElement(int val);
    /**
     * check if the element is in tree
     * @param value value of element
     * @return true, if element is found, false, if element isn't found
     */
    bool findElement(int val);




//private:
    Node* left;
    Node* right;
    int value;

};

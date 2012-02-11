#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "tree.h"
#include <iostream>

class TreeTest:public QObject
{
    Q_OBJECT

public:
    explicit TreeTest(QObject *parent = 0){}

private slots:
    void init()
    {
        t = new Tree();
    }

    void cleanup()
    {
        delete t;
    }
    void addElementTest()
    {
        t->addElement(1);
        t->addElement(2);
        t->addElement(3);
        QVERIFY(t->getRoot()->getValue() == 1);
    }
    void isEmptyTest()
    {
        t->addElement(2);
        QVERIFY(!t->isEmpty());
    }

    void findElementTest()
    {
        t->addElement(4);
        t->addElement(5);
        t->addElement(7);
        QVERIFY(t->findElement(5));

    }

    void treeIteratorTest()
    {
        t->addElement(3);
        Tree::TreeIterator* it = new Tree::TreeIterator(t);
        QVERIFY(it->operator++() == 3);
    }

    void treeIteratorTest2()
    {
        t->addElement(5);
        t->addElement(3);
        t->addElement(7);
        Tree::TreeIterator* it = new Tree::TreeIterator(t);
        QVERIFY(it->operator ++() == 5);
        QVERIFY(it->operator ++() == 3);
        QVERIFY(it->operator ++() == 7);
    }


private:
    Tree *t;


};

QTEST_MAIN(TreeTest)

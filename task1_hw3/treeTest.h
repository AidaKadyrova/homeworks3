#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "tree.h"


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
        t->addElement(3);
        t->addElement(1);
        t->addElement(2);
        Tree::TreeIterator* it = new Tree::TreeIterator(t);
        QVERIFY(t->getRoot()->getValue() == 3);
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
        t->treeIteratorList.push_back(it);
        QVERIFY(t->treeIteratorList.at(0)->operator++() == 3);
    }

    void addElementIteratorTest()
    {
        t->addElement(4);
        t->addElement(1);
        t->addElement(6);
        t->addElement(5);

        Tree::TreeIterator* it = new Tree::TreeIterator(t);
        t->treeIteratorList.push_back(it);

        QVERIFY(it->operator ++() == 4);
        QVERIFY(it->operator ++() == 1);

        t->addElement(3);
        t->addElement(2);
        t->addElement(7);

        QVERIFY(it->operator ++() == 3);
        QVERIFY(it->operator ++() == 2);
        QVERIFY(it->operator ++() == 6);
        QVERIFY(it->operator ++() == 5);
        QVERIFY(it->operator ++() == 7);
    }

    void iteratorListTest()
    {
        t->addElement(4);
        t->addElement(1);
        t->addElement(6);

        Tree::TreeIterator* it = new Tree::TreeIterator(t);
        t->treeIteratorList.push_back(it);
        QVERIFY(t->treeIteratorList.at(0)->operator++() == 4);
        QVERIFY(t->treeIteratorList.at(0)->operator++() == 1);

        Tree::TreeIterator* it1 = new Tree::TreeIterator(t);
        t->treeIteratorList.push_back(it1);

        QVERIFY(t->treeIteratorList.at(1)->operator++() == 4);

        t->addElement(2);
        QVERIFY(t->treeIteratorList.at(0)->operator++() == 2);
        QVERIFY(t->treeIteratorList.at(1)->operator++() == 1);

        t->addElement(5);
        QVERIFY(t->treeIteratorList.at(1)->operator++() == 2);
        QVERIFY(t->treeIteratorList.at(1)->operator++() == 6);
        QVERIFY(t->treeIteratorList.at(1)->operator++() == 5);

    }


private:
    Tree *t;



};

QTEST_MAIN(TreeTest)

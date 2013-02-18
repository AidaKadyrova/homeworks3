#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "tree.h"

#include <vector>

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
        t->addElement(4);
        t->addElement(5);
        int i = 1;

        for(Tree::TreeIterator it = t->begin(); it != t->end(); ++it )
        {
            QVERIFY(*it == i);
            i++;
        }
    }
    void deleteCurrentElementTest()
    {
        t->addElement(3);
        t->addElement(1);
        t->addElement(2);
        t->addElement(4);

        Tree::TreeIterator it = t->begin();
        t->deleteElement(1);
        ++it;
        //it.deleteCurrent();
        t->deleteElement(2);
        ++it;
        QVERIFY(*it == 3);
    }

    void deleteSubTreeTest()
    {
        for (int i = 1; i <= 10; ++i)
            t->addElement(i);
        for (Tree::TreeIterator it = t->begin(); it != t->end(); ++it)
        {
            if (*it > 5)
                it.deleteCurrent();
        }
        std::vector<int> result;
        for (Tree::TreeIterator it = t->begin(); it != t->end(); ++it)
            result.push_back(*it);
        QVERIFY(result.size() == 5);
        for (int i = 0; i < 5; ++i) {
            QVERIFY(result[i] == i + 1);
        }
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

    void twoIteratorDeleteTest()
    {
        t->addElement(4);
        t->addElement(1);
        t->addElement(6);
        t->addElement(5);
        t->addElement(2);
        t->addElement(3);
        Tree::TreeIterator it = t->begin();
        Tree::TreeIterator it1 = t->begin();
        ++it1;
        ++it1;
        // now it1.current = 3; it.current = 1;
        t->deleteElement(3);
        QVERIFY(+*it == 1);
        QVERIFY(*(++it) == 2);
        QVERIFY(*(++it) == 4);
        QVERIFY(*(++it1) == 4);
    }


private:
    Tree *t;

};

QTEST_MAIN(TreeTest)

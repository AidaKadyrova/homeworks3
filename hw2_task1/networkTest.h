#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "network.h"
#include <iostream>

using namespace network;


class networkTest:public QObject
{
    Q_OBJECT

public:
    explicit networkTest(QObject *parent = 0){}



private slots:

    void startWorkingTest()
    {

        a->connect(b);
        c->connect(a);
        b->setPwned();
        b->connect(c);
        n->add(a);
        n->add(b);
        n->add(c);
        n->startNetworking();
        QVERIFY(a->isPwned());
        QVERIFY(c->isPwned());

    }
    void init()
    {
        int array[10] = {4, 50, 6, 16, 90, 44, 11, 23, 9, 88};
        r = new Stupidrandom(&array[0]);
        n = new Network(r);
        a = new Computer("linComp", linuxOS);
        b = new Computer("winComp", windows);
        c = new Computer("macComp", macOS);
    }

    void cleanup()
    {
        delete a;
        delete b;
        delete c;
    }

    void createTest()
    {
        QVERIFY(a->isPwned() == false);
        QVERIFY(a->getOS() == linuxOS);
        QVERIFY(a->getName() == "linComp");
    }

    void setPwnedTest()
    {
        a->setPwned();
        QVERIFY(a->isPwned() == true);
    }

    void attackLinuxTest()
    {
        QVERIFY(!a->isPwned());
        b->connect(a);
        b->attack(40);
        QVERIFY(!a->isPwned());
        b->attack(60);
        QVERIFY(a->isPwned());
    }
    void attackMacTest()
    {
        QVERIFY(!c->isPwned());
        b->connect(c);
        b->attack(60);
        QVERIFY(!c->isPwned());
        b->attack(95);
        QVERIFY(c->isPwned());
    }

    void attackWindowsTest()
    {
        QVERIFY(!b->isPwned());
        c->connect(b);
        c->attack(10);
        QVERIFY(b->isPwned());
    }
private:
    Computer *a;
    Computer *b;
    Computer *c;
    Network* n;
    Random* r;
};

QTEST_MAIN(networkTest)

#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>


class Random
{
public:
    virtual int ran() = 0;
};

class RealRandom: public Random
{
public:
    int ran()
    {
        srand(time(0));
        return rand() % 100;

    }
};

class Stupidrandom: public Random
{
public:
    Stupidrandom(int *myarray):index(0), arraysize(10)
    {
        for (int i = 0; i < arraysize; i++)
            arr[i] = *(myarray+i);
    }

    int ran()
    {
        return arr[index++ / 10];
    }
private:
    int index;
    const int arraysize;
    int arr[arraysize];
};

#pragma once
#include "computer.h"
#include <iostream>
#include "random.h"

namespace network {

class Network
{
public:
    Network(Random* r) {myRandom = r;}
    /**
     * add computer to network
     * @param cmp computer to add
     */
    inline void add(network::Computer *cmp)
    {
        mNormalComputers.push_back(cmp);
    }

    int startNetworking();
    /**
     * update network's state
     */
    void updatePwned();

private:
    /**
     * print current state
     */
    void printStatus();
    std::vector<Computer*> mNormalComputers;
    std::vector<Computer*> mPwnedComputers;
    bool mNetworkIsPwned;
    Random* myRandom;

};
}

#include "network.h"
#include <cstdlib>
#include <ctime>

using namespace network;

int Network::startNetworking() {
    updatePwned();
    if (mPwnedComputers.size() == 0) {
        std::cout << "no viruses" << std::endl;
        return 1;
    }
    std::cout << "Starting: " << std::endl;
    printStatus();
    while (!mNetworkIsPwned) {
        std::cout << "new iteration" <<std::endl;
        for (int i = 0; i < mPwnedComputers.size(); i++) {

            srand(time(0));
            int attackPower = rand() % 100;
            mPwnedComputers[i]->attack(attackPower);
        }
        updatePwned();
        printStatus();
    }
    return 0;
}

void Network::updatePwned() {
    for (int i = 0; i < mNormalComputers.size(); i++) {
        if (mNormalComputers[i]->isPwned()) {
            mPwnedComputers.push_back(mNormalComputers[i]);
            mNormalComputers.erase(mNormalComputers.begin() + i);
        }
    }
    if (mNormalComputers.size() == 0) {
        mNetworkIsPwned = true;
    }
}

void Network::printStatus() {
    for (int i = 0; i < mPwnedComputers.size(); i++) {
        if (mPwnedComputers[i]->isPwned())
            std::cout << "pwned: " << mPwnedComputers[i]->getName() << std::endl;
    }
    std::cout << std::endl;
}

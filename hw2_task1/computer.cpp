#include "computer.h"
#include <cstdlib>
#include <ctime>

void network::Computer::attack(int attackPower) {
    for (int i = 0; i < mConnections.size(); i++) {
        if (mConnections[i]->isPwned())
            continue;
        network::OS targetOS = mConnections[i]->getOS();
        if (targetOS == network::windows)
        {
            mConnections[i]->setPwned();
        } else
        {
            if (targetOS == network::linuxOS)
            {
                if (attackPower > 40)
                {
                    mConnections[i]->setPwned();
                }
            } else if (targetOS == network::macOS)
                if (attackPower > 60)
                {
                    mConnections[i]->setPwned();
                }
        }
    }
}

void network::Computer::connect(Computer *secondComputer)
{
    for (int i = 0; i < mConnections.size(); i++)
    {
        if (mConnections[i]->getName() == secondComputer->getName())
        {
            return;
        }
    }

    mConnections.push_back(secondComputer);
    secondComputer->connect(this);
}



#include "computer.h"
#include <cstdlib>
#include <ctime>

void network::Computer::attack() {
    for (int i = 0; i < mConnections.size(); i++) {
        if (mConnections[i]->isPwned())
            continue;
        network::OS targetOS = mConnections[i]->getOS();
        if (targetOS == network::windows)
        {
            mConnections[i]->setPwned();
        } else
        {
            srand(time(0));
            int attackPower = rand() % 100;
            if (targetOS == network::linuxOS)
            {
                if (attackPower > 70)
                {
                    mConnections[i]->setPwned();
                }
            } else if (targetOS == network::macOS)
                if (attackPower > 90)
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



#pragma once

#include <string>
#include <vector>

namespace network
{
    enum OS
    {
        windows, macOS, linuxOS
    };

class Computer
{
public:
    /**
     * constructor for Computer
     * @param name name of the computer
     * @param OS operating system
     */
    Computer (std::string name, network::OS oS)
        : mOS(oS)
        , mName(name)
        , mIsPwned(false)
    {
    }
    /**
     * get computer's name
     * @return mName computer's name
     */
    inline std::string getName() const{ return mName; }
    /**
     * get computer's OS
     * @return mOS computer's OS
     */
    inline const network::OS getOS() const{ return mOS; }
    /**
     * check if computer is infected
     * @return true, if computer is infected, false, if computer isn't infected
     */
    inline const bool isPwned() const{ return mIsPwned; }

    inline void setPwned() {mIsPwned = true; }
    /**
     * connect two computers to each other
     * @param secondComputer
     */
    void connect(Computer *secondComputer);
    /**
     * infect the computer
     */
    void attack();
private:
    std::string mName;
    network::OS mOS;
    std::vector<Computer*> mConnections;
    bool mIsPwned;
};
}


#include "network.h"
using namespace network;

int main()
{

    Network n;
    Computer *a = new Computer("linComp", linuxOS);
    Computer *b = new Computer("winComp", windows);
    a->connect(b);
    Computer *c = new Computer("macComp", macOS);
    c->connect(a);
    b->setPwned();
    b->connect(c);
    n.add(a);
    n.add(b);
    n.add(c);
    n.startNetworking();

    delete a;
    delete b;
    delete c;
}

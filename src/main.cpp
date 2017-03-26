#include "CParceArgs.h"
#include "CParcePcap.h"

int main(int argc, char *argv[])
{
    CParceArgs * args = new CParceArgs(argc,argv);
    CParcePcap * pcap = new CParcePcap(args->getNameFile(),args->getIpFilter(),args->getPortFilter());
    pcap->parse();

    delete pcap;
    delete args;

    return 0;
}

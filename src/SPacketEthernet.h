#pragma once

#include <stdint.h>
#include <iostream>

struct SPacketEthernet
{
    uint8_t macDestination[6];
    uint8_t macSource[6];
    uint16_t typeProtocol; //EProtocolEthernet

    void clear();
    void print();
};

struct SProtocolEthernet
{
    enum EProtocolEthernet
    {
        IP = 8
        //        PUP = 512,
        //        SPRITE = 1280,
        //        IP = 8,
        //        ARP = 2054,
        //        REVARP = 32821,
        //        AT = 32923,
        //        AARP = 33011,
        //        VLAN = 33024,
        //        IPX = 33079,
        //        IPV6 = 34525,
        //        LOOPBACK = 36864,
        //        PPPOED = 34915,
        //        PPPOES = 34916,
        //        MPLS = 34887,
        //        PPP = 34827
    };
};

void SPacketEthernet::clear()
{
    macDestination[0]=0;
    macDestination[1]=0;
    macDestination[2]=0;
    macDestination[3]=0;
    macDestination[4]=0;
    macDestination[5]=0;
    macSource[0]=0;
    macSource[1]=0;
    macSource[2]=0;
    macSource[3]=0;
    macSource[4]=0;
    macSource[5]=0;
    typeProtocol=0;
}

void SPacketEthernet::print()
{
    std::cout << "SPacketEthernet{" << std::endl
              << "   macDestination = [" << int(macDestination[0]) << "."
                                         << int(macDestination[1]) << "."
                                         << int(macDestination[2]) << "."
                                         << int(macDestination[3]) << "."
                                         << int(macDestination[4]) << "."
                                         << int(macDestination[5]) << "]" << std::endl
              << "   macDestination = [" << int(macDestination[0]) << "."
                                         << int(macDestination[1]) << "."
                                         << int(macDestination[2]) << "."
                                         << int(macDestination[3]) << "."
                                         << int(macDestination[4]) << "."
                                         << int(macDestination[5]) << "]" << std::endl
              << "   typeProtocol = " << long(typeProtocol) << std::endl
              << "}" << " sizeof(SPacketEthernet) = " << sizeof(SPacketEthernet) << std::endl;
}

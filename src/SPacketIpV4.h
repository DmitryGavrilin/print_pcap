#pragma once

#include <stdint.h>
#include <iostream>

struct SPacketIpV4
{
    uint8_t ipVersion:4;
    uint8_t internetHeaderLength:4;
    uint8_t typeOfService;
    uint16_t totalLength;
    uint16_t ipId;
    uint16_t fragmentOffset;
    uint8_t timeToLive;
    uint8_t protocolIpDatagram; //EProtocolPacketIpV4
    uint16_t headerChecksum;
    uint8_t ipSource[4];
    uint8_t ipDestination[4];

    void clear();
    void print();
};

struct SProtocolPacketIpV4
{
    enum EProtocolPacketIpV4
    {
        IP = 0,
        HOPOPTS = 0,
        ICMP = 1,
        IGMP = 2,
        IPIP = 4,
        TCP = 6,
        EGP = 8,
        PUP = 12,
        UDP = 17,
        IDP = 22,
        IPV6 = 41,
        ROUTING = 43,
        FRAGMENT = 44,
        GRE = 47,
        ESP = 50,
        AH = 51,
        ICMPV6 = 58,
        NONE = 59,
        DSTOPTS = 60,
        RAW = 255,
        MAX
    };
};

void SPacketIpV4::clear()
{
    ipVersion = 4;
    internetHeaderLength = 4;
    typeOfService = 0;
    totalLength = 0;
    ipId = 0;
    fragmentOffset = 0;
    timeToLive = 0;
    protocolIpDatagram = 0;
    headerChecksum = 0;
    ipSource[0] = 0;
    ipSource[1] = 0;
    ipSource[2] = 0;
    ipSource[3] = 0;
    ipDestination[0] = 0;
    ipDestination[1] = 0;
    ipDestination[2] = 0;
    ipDestination[3] = 0;
}

void SPacketIpV4::print()
{
    std::cout << "SPacketIpV4{" << std::endl
              << "   ipVersion = " << int(ipVersion) << std::endl
              << "   internetHeaderLength = " << int(internetHeaderLength) << std::endl
              << "   typeOfService = " << int(typeOfService) << std::endl
              << "   totalLength = " << long(totalLength) << std::endl
              << "   ipId = " << long(ipId) << std::endl
              << "   fragmentOffset = " << long(fragmentOffset) << std::endl
              << "   timeToLive = " << int(timeToLive) << std::endl
              << "   protocolIpDatagram = " << int(protocolIpDatagram) << std::endl
              << "   headerChecksum = " << long(headerChecksum) << std::endl
              << "   ipSource = [" << int(ipSource[0]) << "."
                                   << int(ipSource[1]) << "."
                                   << int(ipSource[2]) << "."
                                   << int(ipSource[3]) << "]" << std::endl
              << "   ipDestination = [" << int(ipDestination[0]) << "."
                                        << int(ipDestination[1]) << "."
                                        << int(ipDestination[2]) << "."
                                        << int(ipDestination[3]) << "]" << std::endl
              << "}" << " sizeof(SPacketIpV4) = " << sizeof(SPacketIpV4) << std::endl;

}

#pragma once

#include <stdint.h>
#include <iostream>

struct SPacketUDP
{
    uint16_t portSource;
    uint16_t portDestination;
    uint16_t length;
    uint16_t headerChecksum;

    void clear();
    void print();
};

void SPacketUDP::clear()
{
    portSource = 0;
    portDestination = 0;
    length = 0;
    headerChecksum = 0;
}

void SPacketUDP::print()
{
    std::cout << "SPacketUDP{" << std::endl
              << "   portSource = " << long(portSource) << std::endl
              << "   portDestination = " << long(portDestination) << std::endl
              << "   length = " << long(length) << std::endl
              << "   headerChecksum = " << long(headerChecksum) << std::endl
              << "}" << " sizeof(SPacketUDP) = " << sizeof(SPacketUDP) << std::endl;
}

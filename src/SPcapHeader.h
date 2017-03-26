#pragma once

#include <stdint.h>
#include <iostream>

struct SPcapHeader
{
    uint32_t magic;
    uint16_t versionMajor;
    uint16_t versionMinor;
    int32_t thisZone;
    uint32_t sigfigs;
    uint32_t snaplen;
    uint32_t typeFisicChanel; //EChanelType

    void clear();
    void print();
};

struct SChanelType
{
    enum EChanelType
    {
        ETHERNET = 1,
        LINUX_SLL = 2,
        CNULL = 3,
        RAW = 4,
        DLT_RAW1 = 5,
        DLT_RAW2 = 6
    };
};

void SPcapHeader::clear()
{
    magic = 0;
    versionMajor = 0;
    versionMinor = 0;
    thisZone = 0;
    sigfigs = 0;
    snaplen = 0;
    typeFisicChanel = 0;
}

void SPcapHeader::print()
{
    std::cout << "SPcapHeader{" << std::endl
              << "   magic = " << magic << std::endl
              << "   versionMajor = " << long(versionMajor) << std::endl
              << "   versionMinor = " << long(versionMinor) << std::endl
              << "   thisZone = " << long(thisZone) << std::endl
              << "   sigfigs = " << sigfigs << std::endl
              << "   snaplen = " << snaplen << std::endl
              << "   typeFisicChanel = " << typeFisicChanel << std::endl
              << "}" << " sizeof(SPcapHeader) = " << sizeof(SPcapHeader) << std::endl;
}

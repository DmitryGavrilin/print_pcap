#pragma once

#include <stdint.h>
#include <iostream>

struct SPacketHeader
{
    uint32_t tv_sec;
    uint32_t tv_usec;
    uint32_t caplen;
    uint32_t len;

    void clear();
    void print();
};

void SPacketHeader::clear()
{
    tv_sec = 0;
    tv_usec = 0;
    caplen = 0;
    len = 0;
}

void SPacketHeader::print()
{
    std::cout << "SPacketHeader{" << std::endl
              << "   tv_sec = " << long(tv_sec) << std::endl
              << "   tv_usec = " << long(tv_usec) << std::endl
              << "   caplen = " << long(caplen) << std::endl
              << "   len = " << long(len) << std::endl
              << "}" << " sizeof(SPacketHeader) = " << sizeof(SPacketHeader) << std::endl;

}

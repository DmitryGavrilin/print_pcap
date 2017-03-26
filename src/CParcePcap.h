#pragma once

#include <string>

struct SPacketIpV4;
struct SPacketUDP;

class CParcePcap
{
public:
    CParcePcap(std::string nameFile, std::string ipFilter, int portFilter);

    void parse();
private:
    std::string nameFile_;
    std::string ipFilter_;
    int portFilter_;

    bool applyFilter(const SPacketIpV4 &ipv4, const SPacketUDP &udp);
    void skip(FILE * file, size_t size);
    void printUDP(const SPacketIpV4 &ipv4, const SPacketUDP &udp, FILE * file, const size_t size);
    void printData(FILE * file, const size_t size);
};

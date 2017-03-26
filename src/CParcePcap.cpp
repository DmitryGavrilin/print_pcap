#include "CParcePcap.h"
#include "SPcapHeader.h"
#include "SPacketHeader.h"
#include "SPacketEthernet.h"
#include "SPacketIpV4.h"
#include "SPacketUDP.h"
#include "utils.h"
#include <cstdio>

CParcePcap::CParcePcap(std::string nameFile, std::string ipFilter, int portFilter)
    : nameFile_(nameFile)
    , ipFilter_(ipFilter)
    , portFilter_(portFilter)
{
}

void CParcePcap::parse()
{
    FILE * pcapFile_ = fopen(nameFile_.c_str(), "rb");
    if(pcapFile_ == NULL)
        return;
    SPcapHeader pcapHeader;
    if( sizeof(pcapHeader) != fread(&pcapHeader, 1, sizeof(pcapHeader), pcapFile_) )
    {
        fclose(pcapFile_);
        return;
    }
    if(pcapHeader.typeFisicChanel == SChanelType::ETHERNET)
    {
        while(!feof(pcapFile_))
        {
            SPacketHeader packetHeader;
            if( sizeof(packetHeader) != fread(&packetHeader, 1, sizeof(packetHeader), pcapFile_) )
                break;
            SPacketEthernet packetEthernet;
            if( sizeof(packetEthernet) != fread(&packetEthernet, 1, sizeof(packetEthernet), pcapFile_) )
                break;
            if(packetEthernet.typeProtocol == SProtocolEthernet::IP)
            {
                SPacketIpV4 packetIpV4;
                if( sizeof(packetIpV4) != fread(&packetIpV4, 1, sizeof(packetIpV4), pcapFile_) )
                    break;
                if(packetIpV4.protocolIpDatagram == SProtocolPacketIpV4::UDP)
                {
                    SPacketUDP packetUDP;
                    if( sizeof(packetUDP) != fread(&packetUDP, 1, sizeof(packetUDP), pcapFile_) )
                        break;
                    if(applyFilter(packetIpV4, packetUDP))
                        printUDP(packetIpV4, packetUDP,pcapFile_,packetHeader.len-sizeof(packetEthernet)-sizeof(packetIpV4)-sizeof(packetUDP));
                    else
                        skip(pcapFile_,packetHeader.len-sizeof(packetEthernet)-sizeof(packetIpV4)-sizeof(packetUDP));
                }
                else
                    skip(pcapFile_, packetHeader.len-sizeof(packetEthernet)-sizeof(packetIpV4));
            }
            else
                skip(pcapFile_, packetHeader.len-sizeof(packetEthernet));
        }
    }
    fclose(pcapFile_);
}

bool CParcePcap::applyFilter(const SPacketIpV4 &ipv4, const SPacketUDP &udp)
{
    if(ipFilter_ == "" && portFilter_ == 0)
        return true;
    if(ipFilter_ != "" && portFilter_ == 0)
    {
        std::string ip = patch::to_string(ipv4.ipDestination[0])+"."+
                patch::to_string(ipv4.ipDestination[1])+"."+
                patch::to_string(ipv4.ipDestination[2])+"."+
                patch::to_string(ipv4.ipDestination[3]);
        if(ip == ipFilter_)
            return true;
        else
        {
            return false;
        }
    }
    if(ipFilter_ != "" && portFilter_ != 0)
    {
        std::string ip = patch::to_string(ipv4.ipDestination[0])+"."+
                patch::to_string(ipv4.ipDestination[1])+"."+
                patch::to_string(ipv4.ipDestination[2])+"."+
                patch::to_string(ipv4.ipDestination[3]);
        if(ip == ipFilter_ && int(udp.portDestination) == portFilter_)
            return true;
        else
        {
            return false;
        }
    }
    return false;
}

void CParcePcap::skip(FILE *file, size_t size)
{
    uint8_t temp_;
    for (int var = 0; var < size; ++var)
    {
        fread(&temp_, 1, sizeof(temp_), file);
    }
}

void CParcePcap::printUDP(const SPacketIpV4 &ipv4, const SPacketUDP &udp, FILE *file, const size_t size)
{
    printf("IP (Source): %d.%d.%d.%d:%d \n", ipv4.ipSource[0]
            , ipv4.ipSource[1]
            , ipv4.ipSource[2]
            , ipv4.ipSource[3]
            , udp.portSource);
    printf("IP (Destination): %d.%d.%d.%d:%d \n", ipv4.ipDestination[0]
            , ipv4.ipDestination[1]
            , ipv4.ipDestination[2]
            , ipv4.ipDestination[3]
            , udp.portDestination);
    printData(file, size);
}

void CParcePcap::printData(FILE *file, const size_t size)
{
    uint8_t temp_;
    std::cout << "Data: " << std::endl;
    for (int var = 0; var < size; ++var)
    {
        fread(&temp_, 1, sizeof(temp_), file);
        printf("%02x ", temp_);
    }
    std::cout << std::endl << std::endl;
}

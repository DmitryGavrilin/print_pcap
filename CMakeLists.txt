cmake_minimum_required(VERSION 2.8)

set(BIN print_pcap)
project( ${BIN} )

set( SOURCE_ROOT src )


aux_source_directory( ${SOURCE_ROOT} SOURCES )

add_executable( ${BIN} ${SOURCES} )


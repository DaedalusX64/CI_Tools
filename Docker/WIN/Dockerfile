FROM ubuntu:resolute-20251130

ARG LIBPNG_VERSION=1.6.52
ARG ZLIB_VERSION=1.3.1

ARG CMAKE_CROSS="-DCMAKE_TOOLCHAIN_FILE=/CI_TOOLS/cmake/mingw-g++.cmake -DCMAKE_INSTALL_PREFIX="/usr/x86_64-w64-mingw32""


#BASE
RUN apt update && \
    apt upgrade && \
    apt install -y git wget mingw-w64 build-essential autoconf libtool autopoint gperf cmake

#CI_TOOLS
RUN git clone https://github.com/daedalusx64/CI_TOOLS && \ 

#SDL2

#PNG
RUN wget "http://prdownloads.sourceforge.net/libpng/libpng-${LIBPNG_VERSION}.tar.gz" -O libpng.tar.gz && \
    tar -xvf libpng.tar.gz && \
    cd libpng-${LIBPNG_VERSION} && \ 
    mkdir build && \ 
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 
#ZLIB
RUN wget "https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/zlib-${ZLIB_VERSION}.tar.gz" -O zlib.tar.gz && \
    tar -xvf zlib.tar.gz && \ 
    cd zlib-${ZLIB_VERSION} && \
    mkdir build && \
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 
    
#GLM
#
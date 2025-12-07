FROM ubuntu:resolute-20251130

ARG LIBPNG_VERSION=1.6.52
ARG ZLIB_VERSION=1.3.1
ARG SDL_VERSION=2.32.10
ARG GLM_VERSION=1.0.2
ARG GLEW_VERSION=2.2.0

ARG CMAKE_CROSS="-DCMAKE_TOOLCHAIN_FILE=/CI_TOOLS/cmake/mingw-g++.cmake -DCMAKE_INSTALL_PREFIX="/usr/x86_64-w64-mingw32""


#BASE
RUN apt update && \
    apt upgrade && \
    apt install -y git wget mingw-w64 build-essential autoconf libtool autopoint gperf cmake unzip

#CI_TOOLS
RUN git clone https://github.com/daedalusx64/CI_TOOLS && \
    cd CI_TOOLS && \
    git pull
#ZLIB
RUN wget "https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/zlib-${ZLIB_VERSION}.tar.gz" -O zlib.tar.gz && \
    tar -xvf zlib.tar.gz && \ 
    cd zlib-${ZLIB_VERSION} && \
    mkdir build && \
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 

    #PNG
RUN wget "http://prdownloads.sourceforge.net/libpng/libpng-${LIBPNG_VERSION}.tar.gz" -O libpng.tar.gz && \
    tar -xvf libpng.tar.gz && \
    cd libpng-${LIBPNG_VERSION} && \ 
    mkdir build && \ 
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 
    
    
    #SDL2
RUN wget "https://github.com/libsdl-org/SDL/archive/refs/tags/release-${SDL_VERSION}.tar.gz" -O SDL.tar.gz && \ 
    tar -xvf SDL.tar.gz && \
    cd SDL-release-${SDL_VERSION} && \
    mkdir build && \
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 

    #GLM
RUN wget "https://github.com/g-truc/glm/archive/refs/tags/${GLM_VERSION}.tar.gz" -O glm.tar.gz && \
    tar -xvf glm.tar.gz && \
    cd glm-${GLM_VERSION} && \
    mkdir build && \
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 

    #GLEW
RUN wget "https://github.com/nigels-com/glew/releases/download/glew-${GLEW_VERSION}/glew-${GLEW_VERSION}.tgz" -O glew.tgz && \
    tar -xvf glew.tgz && \
    cd glew-${GLEW_VERSION}/build/cmake && \
    mkdir build && \
    cd build && \
    cmake ${CMAKE_CROSS} .. && \ 
    make -j$(nproc) && \ 
    make install 

    #sqlite - just the basics
RUN cd /CI_TOOLS/cmake/SQLite3 && \
    git pull && \
    wget "https://sqlite.org/2025/sqlite-amalgamation-3510100.zip" -O sqlite.zip && \
    unzip -jo sqlite.zip -d . && \
    mkdir build && \
    cd build && \
    ls && \
    cmake ${CMAKE_CROSS} .. && \
    make -j$(nproc) && \
    make install

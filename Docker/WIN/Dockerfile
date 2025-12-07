
ARG LIBPNG_VERSION=1.6.52

#BASE
RUN apt install -y mingw-w64 build-essential autoconf libtool autopoint gperf cmake

#CI_TOOLS
git clone https://github.com/daedalusx64/CI_TOOLS
#SDL2

#PNG
RUN wget http://prdownloads.sourceforge.net/libpng/libpng-${LIBPNG_VERSION}.tar.gz?download && \
    cd libpng-${LIBPNG_VERSION} \ 
    && mkdir build \ 
    && cmake .. cmake  -DCMAKE_TOOLCHAIN_FILE=~/CI_TOOLS/cmake/mingw-g++.cmake -DCMAKE_INSTALL_PREFIX="/usr/x86_64-w64-mingw32"..
#ZLIB
#GLM
#
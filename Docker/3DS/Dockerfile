FROM devkitpro/toolchain-base

MAINTAINER Dave Murphy <davem@devkitpro.org>

RUN dkp-pacman -Syyu --noconfirm && \
    dkp-pacman -S --needed --noconfirm 3ds-dev && \
    dkp-pacman -S --needed --noconfirm 3ds-portlibs armv4t-portlibs && \
    yes | dkp-pacman -Scc

ENV DEVKITARM=${DEVKITPRO}/devkitARM

# Setup GLM
RUN git clone https://github.com/g-truc/glm
 cd glm && \
 cmake "-DCMAKE_TOOLCHAIN_FILE="$DEVKITPRO/cmake/3DS.cmake" . && \
 make; make install

# Setup PicaGL
RUN git clone https://github.com/masterfeizz/picaGL && \ 
    cd picaGL && \
    git checkout --track origin/revamp && \
    make; make install 

# Setup Imgui-picagl

RUN git clone https://github.com/masterfeizz/imgui-picagl && \ 
    cd imgui-picagl && \
    make; make install 

# Setup SQLite3
RUN wget https://sqlite.org/2025/sqlite-amalgamation-3510100.zip
unzip -Cj sqlite-amalgamation-3510100.zip -d sqlite3
cd sqlite3


# Setup Makerom

RUN	apt-get update && \
	apt-get -y install libyaml-dev libmbedtls-dev build-essential && \
	git clone https://github.com/wally4000/Project_CTR --depth=1 && \
	cd Project_CTR && \
	make && \
	cp makerom/bin/makerom /usr/local/bin

# Update CMake
RUN 	apt-get install -y python3-pip && \
	pip3 install cmake && \
     	cmake --version
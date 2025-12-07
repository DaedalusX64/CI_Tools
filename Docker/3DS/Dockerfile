FROM devkitpro/toolchain-base

RUN dkp-pacman -Syyu --noconfirm && \
    dkp-pacman -S --needed --noconfirm 3ds-dev && \
    dkp-pacman -S --needed --noconfirm 3ds-portlibs armv4t-portlibs && \
    yes | dkp-pacman -Scc

ENV DEVKITARM=${DEVKITPRO}/devkitARM

# Setup GLM
RUN git clone https://github.com/g-truc/glm && \
    cd glm && \
    cmake -DCMAKE_TOOLCHAIN_FILE="$DEVKITPRO/cmake/3DS.cmake" . && \
    make && \
    make install

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
RUN git clone https://github.com/daedalusx64/ci_tools && \
    cd ci_tools/3DS/SQLite3 && \
    cmake -DCMAKE_TOOLCHAIN_FILE="$DEVKITPRO/cmake/3DS.cmake" -DCTR=ON . && \
    make && \
    make install

# Setup Makerom

RUN	apt-get update && \
	apt-get -y install libyaml-dev libmbedtls-dev build-essential && \
	git clone https://github.com/wally4000/Project_CTR --depth=1 && \
	cd Project_CTR && \
	make && \
	cp makerom/bin/makerom /usr/local/bin

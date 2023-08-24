FROM ubuntu:latest

RUN \
    apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install \
        build-essential \
        openssl \
        libssl-dev \
        pkg-config \
        valgrind \
        python3-pip \
        wget \
        tar \
        g++-12

RUN \
   wget https://github.com/Kitware/CMake/releases/download/v3.27.3/cmake-3.27.3.tar.gz -O /cmake-3.27.3.tar.gz && \
    tar zxvf /cmake-3.27.3.tar.gz -C /
WORKDIR /cmake-3.27.3
RUN \
   /cmake-3.27.3/bootstrap && \
    make -j4 && \
    make install
WORKDIR /

RUN \
    rm -rf /cmake-3.27.3 && \
    rm /cmake-3.27.3.tar.gz

RUN \
   apt-get -y install \
       ninja-build

RUN \
   wget https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz -O /googletest.tar.gz && \
    tar zxvf /googletest.tar.gz -C / && \
    cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -S /googletest-1.14.0 -B /googletest-1.14.0/build && \
    cmake --build /googletest-1.14.0/build -j4 && \
    cmake -E chdir /googletest-1.14.0/build ctest --build-config Release && \
    cmake --build /googletest-1.14.0/build --target install && \
    rm -rf /googletest-1.14.0 && \
    rm /googletest.tar.gz

RUN \
    pip install cpplint
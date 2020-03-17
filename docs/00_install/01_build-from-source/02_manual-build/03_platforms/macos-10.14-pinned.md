---
content_title: MacOS 10.14 (pinned compiler)
---

This section contains shell commands to manually download, build, install, test, and uninstall ARISEN and dependencies on MacOS 10.14.

[[info | Building ARISEN is for Advanced Developers]]
| If you are new to ARISEN, it is recommended that you install the [ARISEN Prebuilt Binaries](../../../00_install-prebuilt-binaries.md) instead of building from source.

Select a task below, then copy/paste the shell commands to a Unix terminal to execute:

* [Download ARISEN Repository](#download-arisen-repository)
* [Install ARISEN Dependencies](#install-arisen-dependencies)
* [Build ARISEN](#build-arisen)
* [Install ARISEN](#install-arisen)
* [Test ARISEN](#test-arisen)
* [Uninstall ARISEN](#uninstall-arisen)

[[info | Building ARISEN on another OS?]]
| Visit the [Build ARISEN from Source](../../index.md) section.

## Download ARISEN Repository
These commands set the ARISEN directories, install git, and clone the ARISEN repository.
```sh
# set ARISEN directories
export ARISEN_LOCATION=~/arisen/rsn
export ARISEN_INSTALL_LOCATION=$ARISEN_LOCATION/../install
mkdir -p $ARISEN_INSTALL_LOCATION
# install git
brew update && brew install git
# clone ARISEN repository
git clone https://github.com/arisenio/arisen.git $ARISEN_LOCATION
cd $ARISEN_LOCATION && git submodule update --init --recursive
```

## Install ARISEN Dependencies
These commands install the ARISEN software dependencies. Make sure to [Download the ARISEN Repository](#download-arisen-repository) first and set the ARISEN directories.
```sh
# install dependencies
brew install cmake python libtool libusb graphviz automake wget gmp pkgconfig doxygen openssl@1.1 jq || :
# Boost Fix: arisen/install/bin/../include/c++/v1/stdlib.h:94:15: fatal error: 'stdlib.h' file not found
SDKROOT="$(xcrun --sdk macosx --show-sdk-path)"
# build clang
export PATH=$ARISEN_INSTALL_LOCATION/bin:$PATH
cd $ARISEN_INSTALL_LOCATION && git clone --single-branch --branch release_80 https://git.llvm.org/git/llvm.git clang8 && cd clang8 && git checkout 18e41dc && \
    cd tools && git clone --single-branch --branch release_80 https://git.llvm.org/git/lld.git && cd lld && git checkout d60a035 && \
    cd ../ && git clone --single-branch --branch release_80 https://git.llvm.org/git/polly.git && cd polly && git checkout 1bc06e5 && \
    cd ../ && git clone --single-branch --branch release_80 https://git.llvm.org/git/clang.git clang && cd clang && git checkout a03da8b && \
    cd tools && mkdir extra && cd extra && git clone --single-branch --branch release_80 https://git.llvm.org/git/clang-tools-extra.git && cd clang-tools-extra && git checkout 6b34834 && \
    mkdir -p $ARISEN_INSTALL_LOCATION/clang8/projects && cd $ARISEN_INSTALL_LOCATION/clang8/projects && git clone --single-branch --branch release_80 https://git.llvm.org/git/libcxx.git && cd libcxx && git checkout 1853712 && \
    cd ../ && git clone --single-branch --branch release_80 https://git.llvm.org/git/libcxxabi.git && cd libcxxabi && git checkout d7338a4 && \
    cd ../ && git clone --single-branch --branch release_80 https://git.llvm.org/git/libunwind.git && cd libunwind && git checkout 57f6739 && \
    cd ../ && git clone --single-branch --branch release_80 https://git.llvm.org/git/compiler-rt.git && cd compiler-rt && git checkout 5bc7979 && \
    mkdir $ARISEN_INSTALL_LOCATION/clang8/build && cd $ARISEN_INSTALL_LOCATION/clang8/build && \
    cmake -G 'Unix Makefiles' -DCMAKE_INSTALL_PREFIX=$ARISEN_INSTALL_LOCATION -DLLVM_BUILD_EXTERNAL_COMPILER_RT=ON -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_ENABLE_LIBCXX=ON -DLLVM_ENABLE_RTTI=ON -DLLVM_INCLUDE_DOCS=OFF -DLLVM_OPTIMIZED_TABLEGEN=ON -DLLVM_TARGETS_TO_BUILD=X86 -DCMAKE_BUILD_TYPE=Release .. && \
    make -j $(getconf _NPROCESSORS_ONLN) && \
    make install && \
    rm -rf $ARISEN_INSTALL_LOCATION/clang8
cd $ARISEN_INSTALL_LOCATION && curl -LO https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2 && \
    tar -xjf boost_1_71_0.tar.bz2 && cd boost_1_71_0 && \
    SDKROOT="$SDKROOT" ./bootstrap.sh --prefix=$ARISEN_INSTALL_LOCATION && \
    SDKROOT="$SDKROOT" ./b2 --with-iostreams --with-date_time --with-filesystem --with-system --with-program_options --with-chrono --with-test -q -j$(getconf _NPROCESSORS_ONLN) install && \
    rm -rf $ARISEN_INSTALL_LOCATION/boost_1_71_0.tar.bz2 $ARISEN_INSTALL_LOCATION/boost_1_71_0
# install mongodb
cd $ARISEN_INSTALL_LOCATION && curl -OL https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.3.tgz
    tar -xzf mongodb-osx-ssl-x86_64-3.6.3.tgz && rm -f mongodb-osx-ssl-x86_64-3.6.3.tgz && \
    mv $ARISEN_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3/bin/* $ARISEN_INSTALL_LOCATION/bin/ && \
    rm -rf $ARISEN_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3
# install mongo-c-driver from source
cd $ARISEN_INSTALL_LOCATION && curl -LO https://github.com/mongodb/mongo-c-driver/releases/download/1.13.0/mongo-c-driver-1.13.0.tar.gz && \
    tar -xzf mongo-c-driver-1.13.0.tar.gz && cd mongo-c-driver-1.13.0 && \
    mkdir -p cmake-build && cd cmake-build && \
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$ARISEN_INSTALL_LOCATION -DENABLE_BSON=ON -DENABLE_SSL=DARWIN -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DENABLE_STATIC=ON -DENABLE_ICU=OFF -DENABLE_SASL=OFF -DENABLE_SNAPPY=OFF .. && \
    make -j $(getconf _NPROCESSORS_ONLN) && \
    make install && \
    rm -rf $ARISEN_INSTALL_LOCATION/mongo-c-driver-1.13.0.tar.gz $ARISEN_INSTALL_LOCATION/mongo-c-driver-1.13.0
# install mongo-cxx-driver from source
cd $ARISEN_INSTALL_LOCATION && curl -L https://github.com/mongodb/mongo-cxx-driver/archive/r3.4.0.tar.gz -o mongo-cxx-driver-r3.4.0.tar.gz && \
    tar -xzf mongo-cxx-driver-r3.4.0.tar.gz && cd mongo-cxx-driver-r3.4.0/build && \
    cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$ARISEN_INSTALL_LOCATION .. && \
    make -j $(getconf _NPROCESSORS_ONLN) VERBOSE=1 && \
    make install && \
    rm -rf $ARISEN_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0.tar.gz $ARISEN_INSTALL_LOCATION/mongo-cxx-driver-r3.4.0
```

## Build ARISEN
These commands build the ARISEN software on the specified OS. Make sure to [Install ARISEN Dependencies](#install-arisen-dependencies) first.
```sh
export ARISEN_BUILD_LOCATION=$ARISEN_LOCATION/build
mkdir -p $ARISEN_BUILD_LOCATION
cd $ARISEN_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_TOOLCHAIN_FILE=$ARISEN_LOCATION/scripts/pinned_toolchain.cmake -DCMAKE_INSTALL_PREFIX=$ARISEN_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true ..
cd $ARISEN_BUILD_LOCATION && make -j$(getconf _NPROCESSORS_ONLN)
```

## Install ARISEN
This command installs the ARISEN software on the specified OS. Make sure to [Build ARISEN](#build-arisen) first.
```sh
cd $ARISEN_BUILD_LOCATION && make install
```

## Test ARISEN
These commands validate the ARISEN software installation on the specified OS. This task is optional but recommended. Make sure to [Install ARISEN](#install-arisen) first.
```sh
$ARISEN_INSTALL_LOCATION/bin/mongod --fork --logpath $(pwd)/mongod.log --dbpath $(pwd)/mongodata
cd $ARISEN_BUILD_LOCATION && make test
```

## Uninstall ARISEN
These commands uninstall the ARISEN software from the specified OS.
```sh
xargs rm < $ARISEN_BUILD_LOCATION/install_manifest.txt
rm -rf $ARISEN_BUILD_LOCATION
```

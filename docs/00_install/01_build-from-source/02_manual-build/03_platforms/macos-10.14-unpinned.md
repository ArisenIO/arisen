---
content_title: MacOS 10.14 (native compiler)
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
git clone https://github.com/ARISENIO/rsn.git $ARISEN_LOCATION
cd $ARISEN_LOCATION && git submodule update --init --recursive
```

## Install Dependencies
These commands install the ARISEN software dependencies. Make sure to [Download the ARISEN Repository](#download-arisen-repository) first and set the ARISEN directories.
```sh
# install dependencies
brew install cmake python libtool libusb graphviz automake wget gmp pkgconfig doxygen openssl@1.1 jq boost || :
export PATH=$ARISEN_INSTALL_LOCATION/bin:$PATH
# install mongodb
mkdir -p $ARISEN_INSTALL_LOCATION/bin
cd $ARISEN_INSTALL_LOCATION && curl -OL https://fastdl.mongodb.org/osx/mongodb-osx-ssl-x86_64-3.6.3.tgz
    tar -xzf mongodb-osx-ssl-x86_64-3.6.3.tgz && rm -f mongodb-osx-ssl-x86_64-3.6.3.tgz && \
    mv $ARISEN_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3/bin/* $ARISEN_INSTALL_LOCATION/bin/ && \
    rm -rf $ARISEN_INSTALL_LOCATION/mongodb-osx-x86_64-3.6.3 && rm -rf $ARISEN_INSTALL_LOCATION/mongodb-osx-ssl-x86_64-3.6.3.tgz
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
cd $ARISEN_BUILD_LOCATION && cmake -DCMAKE_BUILD_TYPE='Release' -DCMAKE_INSTALL_PREFIX=$ARISEN_INSTALL_LOCATION -DBUILD_MONGO_DB_PLUGIN=true ..
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

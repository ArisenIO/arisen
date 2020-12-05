# ARISEN 
This is the core software for the ARISEN blockchain. ARISEN enables businesses to rapidly build and deploy high-performance and high-security blockchain-based applications.

NOTE: You can use the [Lunar Installer](https://github.com/peepsx/lunar) to install ARISEN in one click. Otherwise, there are shell scripts included in this repo that will allow for you to install ARISEN just as easily.

## Features
- Free Rate Limited Transaction
- Low Latency Block Confirmation (0.5 seconds)
- Low-overhead Byzantine Fault Tolerant Finality
- Designed for optional high-overhead, low-latency BFT finality
- Smart Contract platform powered by WebAssembly (WASM)
- Designed for Sparse Header Light Client Validation
- Scheduled Recurring Transactions
- Time Delay Security
- Hierarchical Role Based Permissions
- Support For Biometric Hardware Secured Keys (e.g. Apple Secure Enclave)
- Designed For Parallel Execution Of Context Free Validation Logic
- Designed For Inter Blockchain Communication
- Integrated With Off-Chain P2P Protocols For File and Data Distribution
- Built-in Decentralized Domain Name System
- Built-in Reporting System For Removing Illicit Material or Halting Illegal Activity Via Governance Intervention

## Disclaimer
Peeps, nor Peeps Labs is launching or operating any initial public blockchains based upon the ARISEN software. This release refers only to version 1.0 of our open source software. We caution those who wish to use blockchains built on ARISEN to carefully vet the companies and organizations launching blockchains based on ARISEN before disclosing any private keys to their derivative software.

## Main Network
ARISEN's main network was launched on January 1st, 2020 on the `greatchains.arisennodes.io` node. There is now 21 elected block producers which can be viewed [here](https://live.arisen.network). 

If you would like to explore the ARISEN Mainnet, please use the below explorers:
- [Mainnet Explorer 1](https://data.arisen.network)
- [Mainnet Explorer 2](https://explorer.arisen.network)

## Supported Operating Systems
ARISEN currently supports the following operating systems:
- Amazon Linux 2
- CentOS 7 
- Ubuntu 16.04
- Ubuntu 18.04
- MacOS 10.14 (Mojave)

NOTE: It is possible to install ARISEN on other Unix-based operating systems although it's not officially supported by Peeps Labs or any of the community's developers.

## Installing ARISEN
You can either install ARISEN via ARISEN's prebuilt binaries or you can do so from source. If you are an advanced developers, a block producers or no binaries are available for your platform, you may need to [Build From Source](#build-from-source)

### Prebuilt Binaries

#### MacOS X:
##### MacOS X Brew Install:
```
brew tap arisenio/arisen
brew install arisen
```

##### MacOS X Brew Uninstall:
```
brew remove arisen
```

#### Ubuntu 
##### Ubuntu 18.04 Package Install
```
wget https://github.com/ArisenIO/arisen/releases/download/1.0/arisen-1.0-v1-amd64_1-2_all.deb
sudo apt install ./arisen-1.0-v1-amd64_1-2_all.deb
```

##### Ubuntu 16.04 Package Install
```
wget https://github.com/arisenio/arisen/releases/download/v1.0.0/arisen_1.0.0-ubuntu-16.04_amd64.deb
sudo apt install ./arisen_1.0.0-ubuntu-16.04_amd64.deb
```

#### RPM-based (CentOS, Amazon Linux, etc.):
##### RPM Package Install
```
wget https://github.com/arisenio/arisen/releases/download/v1.0.0/arisen-1.0.0.el7.x86_64.rpm
sudo yum install ./arisen-1.0.0.el7.x86_64.rpm
```

##### RPM Package Uninstall
```
sudo yum remove arisen
```

### Uninstall Script
To uninstall the ARISEN built/installed binaries and dependencies, run:
```
./scripts/arisen_uninstall.sh
```

### Build From Source
```
git clone https://github.com/arisenio/arisen.git
cd arisen
./arisen_install.sh
./arisen_build.sh
```

## Documentation
ARISEN's official documentation, can be found at [https://docs.arisen.network](https://docs.arisen.network). It is extensive and covers everything from `aOS`, `arisecli` and `awalletd`, to many of the off-chain based protocols that developers can use to publish their websites or applications on the `dweb://`. 

## Resources
- [Website](https://arisen.network)
- [Peeps Labs Blog](https://peepsology.medium.com/)
- [Arisen Blog](https://steemit.com/@arisenio
- [Community Telegram Group](https://t.me/AriseArmy)
- [Developer Telegram Group](https://t.me/arisenio)
- [Whitepaper](https://github.com/arisenio/technical-whitepaper)
- [dWeb Website](https://dwebx.org)
- [dBrowser Website](http://dbrowser.com)
- [dWallet](https://peepsx.com/dwallet)

## Related Software
- [arisen.contracts](https://github.com/arisenio/arisen.contracts)
- [arisen.cdt](https://github.com/arisenio/arisen.cdt)
- [dDrive Daemon](https://github.com/distributedweb/ddrive-daemon)


## Contributing
- [Contributing Guide](CONTRIBUTING.md)
- [ARISEN Constitution](https://github.com/arisenio/constitution)

## License
ARISEN is released under the open source [MIT](LICENSE.md) license and is offered "AS IS" without warranty of any kind, express or implied. Any security provided by the ARISEN software depends in part on how it is used, configured, and deployed. ARISEN is built upon many third-party libraries such as WABT (Apache License) and WAVM (BSD 3-clause) which are also provided "AS IS" without warranty of any kind. Without limiting the generality of the foregoing, Peeps Labs makes no representation or guarantee that ARISEN or any third-party libraries will perform as intended or will be free of errors, bugs or faulty code. Both may fail in large or small ways that could completely or partially limit functionality or compromise computer systems. If you use or implement ARISEN, you do so at your own risk. In no event will Peeps Labs be liable to any party for any damages whatsoever, even if it had been advised of the possibility of damage.


## Important
See [LICENSE](LICENSE.md) for copyright and license terms.

All repositories and other materials are provided subject to the terms of this IMPORTANT notice and you must familiarize yourself with these terms. The notice contains important information, limitations and restrictions relating to our software, publications, trademarks, third-party resources, and forward-looking statements. By accessing any of our repositories and other materials, you accept and agree to the terms of the notice.

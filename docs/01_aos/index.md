---
content_title: Aos
---

## Introduction

`aos` is the core service daemon that runs on every ARISEN node. It can be configured to process smart contracts, validate transactions, produce blocks containing valid transactions, and confirm blocks to record them on the blockchain.

## Installation

`aos` is distributed as part of the [ARISEN software suite](https://github.com/ARISEN/rsn/blob/master/README.md). To install `aos`, visit the [ARISEN Software Installation](../00_install/index.md) section.

## Explore

Navigate the sections below to configure and use `aos`.

* [Usage](02_usage/index.md) - Configuring and using `aos`, node setups/environments.
* [Plugins](03_plugins/index.md) - Using plugins, plugin options, mandatory vs. optional.
* [Replays](04_replays/index.md) - Replaying the chain from a snapshot or a blocks.log file.
* [Logging](06_logging/index.md) - Logging config/usage, loggers, appenders, logging levels.
* [Upgrade Guides](07_upgrade-guides/index.md) - ARISEN version/consensus upgrade guides.
* [Troubleshooting](08_troubleshooting/index.md) - Common `aos` troubleshooting questions.

[[info | Access Node]]
| A local or remote ARISEN access node running `aos` is required for a client application or smart contract to interact with the blockchain.

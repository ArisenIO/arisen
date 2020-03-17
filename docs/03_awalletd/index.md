---
content_title: Awalletd
---

## Introduction

`awalletd` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `awalletd` also defines a secure enclave for signing transaction created by `arisecli` or a third part library.

## Installation

`awalletd` is distributed as part of the [ARISEN software suite](https://github.com/arisenio/arisen/blob/master/README.md). To install `awalletd` just visit the [ARISEN Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `arisecli` can request `awalletd` to sign a transaction with the appropriate private keys. Also, `awalletd` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `awalletd` is intended to be used by ARISEN developers only.

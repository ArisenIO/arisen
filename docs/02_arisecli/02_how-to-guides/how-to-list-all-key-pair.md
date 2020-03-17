## Goal

List all key pairs

## Before you begin

* Install the currently supported version of `arisecli`

* Understand the following:
  * What is a public and private key pair

## Steps

Unlock your wallet

```sh
arisecli wallet unlock
```

List all public keys:

```sh
arisecli wallet keys
```

List all private keys:

```sh
arisecli wallet private_keys

```

[[warning]]
| Be careful never real your private keys in a production enviroment

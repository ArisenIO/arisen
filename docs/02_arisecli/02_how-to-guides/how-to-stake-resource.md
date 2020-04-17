## Goal

Stake resource for your account

## Before you begin

* Install the currently supported version of `arisecli`

* Ensure the reference system contracts from `arisen.contracts` repository is deployed and used to manage system resources

* Understand the following:
  * What is an account
  * What is network bandwidth
  * What is CPU bandwidth

## Steps

Stake 0.01 RIX network bandwidth for `alice`

```sh
arisecli system delegatebw alice alice "0 RIX" "0.01 RIX"
```

Stake 0.01 RIX CPU bandwidth for `alice`:

```sh
arisecli system delegatebw alice alice "0.01 RIX" "0 RIX"
```